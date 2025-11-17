import java.util.*;

public class RashikhBox {
    static class State {
        int cx, cy, dir, steps; // center coordinates, dir: 0=H,1=V
        State(int cx, int cy, int dir, int steps) {
            this.cx = cx; this.cy = cy; this.dir = dir; this.steps = steps;
        }
    }

    static int M, N, L;
    static char[][] grid;
    static boolean[][][] vis; // vis[cx][cy][dir]
    // 4-neighbor moves for the center
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        L = sc.nextInt();
        grid = new char[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = sc.next().charAt(0);
            }
        }

        // Build start state from L cells marked 'L'
        State start = findStartByLCells();
        if (start == null) {
            System.out.println("Impossible");
            return;
        }

        vis = new boolean[M][N][2];
        int ans = bfs(start);
        System.out.println(ans == -1 ? "Impossible" : ans);
    }

    // Finds center and orientation from exactly L cells labeled 'L'
    static State findStartByLCells() {
        List<int[]> cells = new ArrayList<>();
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 'L') cells.add(new int[]{i, j});

        if (cells.size() != L) return null;

        // Determine if aligned horizontally or vertically
        boolean sameRow = true, sameCol = true;
        int r0 = cells.get(0)[0], c0 = cells.get(0)[1];
        for (int[] p : cells) {
            sameRow &= (p[0] == r0);
            sameCol &= (p[1] == c0);
        }
        int dir;
        if (sameRow) dir = 0;      // horizontal
        else if (sameCol) dir = 1; // vertical
        else return null;

        // Find center as the median along the occupied cells
        // Sort by column if horizontal, by row if vertical
        cells.sort((a, b) -> dir == 0 ? Integer.compare(a[1], b[1])
                                      : Integer.compare(a[0], b[0]));
        int midIdx = L / 2; // works for odd or even L
        int cx, cy;
        if (dir == 0) { // horizontal: same row, median column
            cx = cells.get(midIdx)[0];
            cy = cells.get(midIdx)[1];
        } else { // vertical: same column, median row
            cx = cells.get(midIdx)[0];
            cy = cells.get(midIdx)[1];
        }

        // Ensure the log placed at this center actually covers all L 'L' cells (sanity)
        if (!occupyMatchesLabel(cx, cy, dir, 'L')) return null;

        return new State(cx, cy, dir, 0);
    }

    static int bfs(State start) {
        ArrayDeque<State> q = new ArrayDeque<>();
        if (!occupyFree(start.cx, start.cy, start.dir)) return -1;
        vis[start.cx][start.cy][start.dir] = true;
        q.add(start);

        while (!q.isEmpty()) {
            State cur = q.poll();
            if (reachedTarget(cur)) return cur.steps;

            // Try 4 moves
            for (int k = 0; k < 4; k++) {
                int nx = cur.cx + dx[k];
                int ny = cur.cy + dy[k];
                if (inBoundsCenter(nx, ny) && occupyFree(nx, ny, cur.dir) && !vis[nx][ny][cur.dir]) {
                    vis[nx][ny][cur.dir] = true;
                    q.add(new State(nx, ny, cur.dir, cur.steps + 1));
                }
            }

            // Try rotation (around center)
            int ndir = 1 - cur.dir;
            if (rotationClear(cur.cx, cur.cy) && occupyFree(cur.cx, cur.cy, ndir) && !vis[cur.cx][cur.cy][ndir]) {
                vis[cur.cx][cur.cy][ndir] = true;
                q.add(new State(cur.cx, cur.cy, ndir, cur.steps + 1));
            }
        }
        return -1;
    }

    // Checks that all L cells for the log at (center cx,cy, orientation dir) are inside and not 'B'
    static boolean occupyFree(int cx, int cy, int dir) {
        if (!inBoundsCenter(cx, cy)) return false;
        int halfL = (L - 1) / 2;
        if (dir == 0) { // horizontal
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx;
                int y = cy + d;
                if (!inBounds(x, y) || grid[x][y] == 'B') return false;
            }
        } else { // vertical
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx + d;
                int y = cy;
                if (!inBounds(x, y) || grid[x][y] == 'B') return false;
            }
        }
        return true;
    }

    // Require the LxL square around the center to be free of 'B' for rotation
    static boolean rotationClear(int cx, int cy) {
        int halfL = (L - 1) / 2;
        for (int dx = -halfL; dx <= halfL; dx++) {
            for (int dy = -halfL; dy <= halfL; dy++) {
                int x = cx + dx, y = cy + dy;
                if (!inBounds(x, y) || grid[x][y] == 'B') return false;
            }
        }
        return true;
    }

    // Check if current placement fully covers target cells 'T'
    static boolean reachedTarget(State s) {
        int cx = s.cx, cy = s.cy, dir = s.dir;
        int halfL = (L - 1) / 2;
        if (dir == 0) { // horizontal
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx, y = cy + d;
                if (!inBounds(x, y) || grid[x][y] != 'T') return false;
            }
            return true;
        } else {
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx + d, y = cy;
                if (!inBounds(x, y) || grid[x][y] != 'T') return false;
            }
            return true;
        }
    }

    // Helper used only to sanity-check the start placement
    static boolean occupyMatchesLabel(int cx, int cy, int dir, char label) {
        int halfL = (L - 1) / 2;
        if (dir == 0) {
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx, y = cy + d;
                if (!inBounds(x, y) || grid[x][y] != label) return false;
            }
        } else {
            for (int d = -halfL; d <= halfL; d++) {
                int x = cx + d, y = cy;
                if (!inBounds(x, y) || grid[x][y] != label) return false;
            }
        }
        return true;
    }

    static boolean inBounds(int x, int y) {
        return x >= 0 && x < M && y >= 0 && y < N;
    }

    // Center must be a valid cell
    static boolean inBoundsCenter(int cx, int cy) {
        return cx >= 0 && cx < M && cy >= 0 && cy < N;
    }
}

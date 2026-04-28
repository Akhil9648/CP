lowx, highx = 0, int(1e9)
lowy, highy = 0, int(1e9)

while True:
    midx = (lowx + highx) // 2
    midy = (lowy + highy) // 2

    print("?", midx, midy, flush=True)
    s = input().strip()

    if s == "HERE":
        print("!", midx, midy, flush=True)
        break

    if "LEFT" in s:
        highx = midx - 1
    if "RIGHT" in s:
        lowx = midx + 1
    if "UP" in s:
        lowy = midy + 1
    if "DOWN" in s:
        highy = midy - 1
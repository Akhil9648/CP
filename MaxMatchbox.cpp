#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <set>

struct Point2D {
    double x_coord, y_coord;
};

struct PolygonMetrics {
    double area;
    double perimeter;
    double min_side_length;
};

class BoxVolumeSolver {
public:
    void run() {
        int num_vertices;
        std::cin >> num_vertices;
        std::vector<Point2D> polygon_points(num_vertices);
        for (int i = 0; i < num_vertices; ++i) {
            std::cin >> polygon_points[i].x_coord >> polygon_points[i].y_coord;
        }

        PolygonMetrics initial_metrics = compute_polygon_metrics(polygon_points);
        double original_area = initial_metrics.area;
        double total_perimeter = initial_metrics.perimeter;
        double shortest_edge = initial_metrics.min_side_length;

        double max_h = calculate_max_height(polygon_points, shortest_edge);

        double best_volume = 0.0;
        int num_height_steps = static_cast<int>(max_h / 0.1);

        if (num_height_steps < 1) {
            std::cout << std::fixed << std::setprecision(2) << 0.00 << std::endl;
            return;
        }

        for (int i = 1; i <= num_height_steps; ++i) {
            double current_h = i * 0.1;
            double inset_area = original_area - total_perimeter * current_h + 4.0 * current_h * current_h;

            if (inset_area > 1e-9) {
                double current_volume = inset_area * current_h;
                if (current_volume > best_volume) {
                    best_volume = current_volume;
                }
            }
        }

        std::cout << std::fixed << std::setprecision(2) << best_volume << std::endl;
    }

private:
    PolygonMetrics compute_polygon_metrics(const std::vector<Point2D>& points) {
        double area_accumulator = 0.0;
        double perimeter_accumulator = 0.0;
        double min_len = std::numeric_limits<double>::max();
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            Point2D p1 = points[i];
            Point2D p2 = points[(i + 1) % n];

            area_accumulator += p1.x_coord * p2.y_coord - p2.x_coord * p1.y_coord;

            double side_len = (p1.x_coord == p2.x_coord)
                            ? std::abs(p1.y_coord - p2.y_coord)
                            : std::abs(p1.x_coord - p2.x_coord);

            perimeter_accumulator += side_len;

            if (side_len > 1e-9) {
                min_len = std::min(min_len, side_len);
            }
        }

        return {std::abs(area_accumulator) / 2.0, perimeter_accumulator, min_len};
    }

    double get_min_coordinate_gap(const std::set<double>& coords) {
        if (coords.size() <= 1) {
            return std::numeric_limits<double>::max();
        }

        double min_gap = std::numeric_limits<double>::max();
        for (auto it = std::next(coords.begin()); it != coords.end(); ++it) {
            min_gap = std::min(min_gap, *it - *std::prev(it));
        }
        return min_gap;
    }

    double calculate_max_height(const std::vector<Point2D>& points, double shortest_edge) {
        std::set<double> x_values, y_values;
        for (const auto& p : points) {
            x_values.insert(p.x_coord);
            y_values.insert(p.y_coord);
        }

        double min_x_spacing = get_min_coordinate_gap(x_values);
        double min_y_spacing = get_min_coordinate_gap(y_values);

        double max_h_from_spacing = std::min(min_x_spacing, min_y_spacing) / 2.0;

        double max_h_from_edge_rule = (shortest_edge > 0.1) ? (shortest_edge - 0.1) / 2.0 : 0.0;

        return std::min(max_h_from_spacing, max_h_from_edge_rule);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    BoxVolumeSolver solver;
    solver.run();

    return 0;
}

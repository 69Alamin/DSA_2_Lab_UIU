#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Compute Euclidean distance
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Find the closest pair in the strip
pair<Point, Point> CrossPair(vector<Point>& points, int low, int mid, int high, double d) {
    vector<Point> strip;

    // Collect points within 'd' distance of mid-line
    for (int i = low; i <= high; i++) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }

    // Sort strip by Y-coordinate
    sort(strip.begin(), strip.end(), [](Point a, Point b) { return a.y < b.y; });

    pair<Point, Point> bestPair = {{-1, -1}, {-1, -1}}; // Initialize with invalid points
    double minDist = d;

    // Only check next 6 points in the sorted strip
    int n = strip.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist; j++) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                bestPair = {strip[i], strip[j]};
            }
        }
    }

    return bestPair;
}

// Divide & conquer approach to find closest pair
pair<Point, Point> ClosestPair(vector<Point>& points, int low, int high) {
    if (high - low <= 3) {
        pair<Point, Point> bestPair = {{-1, -1}, {-1, -1}};
        double minDist = DBL_MAX;
        for (int i = low; i < high; i++) {
            for (int j = i + 1; j <= high; j++) {
                double d = distance(points[i], points[j]);
                if (d < minDist) {
                    minDist = d;
                    bestPair = {points[i], points[j]};
                }
            }
        }
        return bestPair;
    }

    int mid = (low + high) / 2;

    // Recursive calls
    pair<Point, Point> pair1 = ClosestPair(points, low, mid);
    pair<Point, Point> pair2 = ClosestPair(points, mid + 1, high);

    double d1 = distance(pair1.first, pair1.second);
    double d2 = distance(pair2.first, pair2.second);
    double d = min(d1, d2);
    pair<Point, Point> bestPair = (d1 < d2) ? pair1 : pair2;

    // Check closest pair in the strip
    pair<Point, Point> crossPair = CrossPair(points, low, mid, high, d);
    if (crossPair.first.x != -1) {  // Only update if valid
        double d3 = distance(crossPair.first, crossPair.second);
        if (d3 < d) {
            bestPair = crossPair;
        }
    }

    return bestPair;
}

// Wrapper function
pair<Point, Point> FindClosestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    return ClosestPair(points, 0, points.size() - 1);
}

// Driver function
int main() {
    vector<Point> arr = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    pair<Point, Point> result = FindClosestPair(arr);

    if (result.first.x != -1) {
        cout << "The closest pair is: (" << result.first.x << ", " << result.first.y << ") and ("
             << result.second.x << ", " << result.second.y << ")\n";
        cout << "Distance: " << distance(result.first, result.second) << endl;
    } else {
        cout << "No valid closest pair found!\n";
    }

    return 0;
}

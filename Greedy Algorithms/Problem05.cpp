#include <bits/stdc++.h>
using namespace std;

vector<pair<double, double>> Smallest_Interval(vector<double> points) {
    sort(points.begin(), points.end());
    vector<pair<double, double>> result;

    int i = 0, n = points.size();
    while (i < n) {
        double start = points[i];
        double end = start + 1.0;
        result.push_back({start, end});
        i++;
        while (i < n && points[i] <= end) {
            i++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<double> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    vector<pair<double, double>> intervals = Smallest_Interval(points);
    for (auto interval : intervals) {
        cout << "Interval: [" << interval.first << ", " << interval.second << "]\n";
    }

    return 0;
}

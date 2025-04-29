#include <bits/stdc++.h>
using namespace std;

void find_min_stops(int D, int m, int n, vector<int>& stations) {
    stations.push_back(D);
    int current_pos = 0;
    int i = 0;
    vector<int> stops;

    while (current_pos + m < D) {
        int next_stop = -1;
        while (i < stations.size() && stations[i] <= current_pos + m) {
            if (stations[i] > current_pos)
                next_stop = i;
            i++;
        }
        if (next_stop == -1) {
            cout << "Can't reach destination" << endl;
            return;
        }
        stops.push_back(next_stop);
        current_pos = stations[next_stop];
    }

    for (int idx : stops) {
        cout << "stop at gas station " << idx + 1 << " ( " << stations[idx] << " miles )" << endl;
    }
}

int main() {
    int D, m, n;
    cin >> D >> m >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    find_min_stops(D, m, n, stations);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<int> degree(n, 0);
        int total = 0;

        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            total += w;
            degree[u]++;
            degree[v]++;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        vector<int> odd;
        for (int i = 0; i < n; ++i)
            if (degree[i] % 2 == 1) odd.push_back(i);

        int k = odd.size();
        vector<int> dp(1 << k, INF);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << k); ++mask) {
            if (dp[mask] == INF) continue;
            int first = -1;
            for (int i = 0; i < k; ++i)
                if (!(mask & (1 << i))) { first = i; break; }
            if (first == -1) continue;

            for (int j = first + 1; j < k; ++j) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << first) | (1 << j);
                    dp[newMask] = min(dp[newMask],
                        dp[mask] + dist[odd[first]][odd[j]]);
                }
            }
        }

        int ans = total + dp[(1 << k) - 1];
        cout << "Case " << cs << ": " << ans << "\n";
    }
}

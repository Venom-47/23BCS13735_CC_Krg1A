#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    int src, dst, k;
    cin >> src >> dst >> k;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    for (int i = 0; i <= k; i++)
    {
        vector<int> tmp = dist;
        for (auto &f : flights)
        {
            if (dist[f[0]] != 1e9)
                tmp[f[1]] = min(tmp[f[1]], dist[f[0]] + f[2]);
        }
        dist = tmp;
    }
    cout << (dist[dst] == 1e9 ? -1 : dist[dst]);
}
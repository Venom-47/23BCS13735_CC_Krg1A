#include <bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>> &p)
{
    int n = p.size(), ans = 1;
    for (int i = 0; i < n; i++)
    {
        map<pair<int, int>, int> m;
        int dup = 0;
        for (int j = i + 1; j < n; j++)
        {
            int dx = p[j][0] - p[i][0], dy = p[j][1] - p[i][1];
            if (dx == 0 && dy == 0)
                dup++;
            else
            {
                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                m[{dx, dy}]++;
            }
        }
        int mx = 0;
        for (auto &x : m)
            mx = max(mx, x.second);
        ans = max(ans, mx + dup + 1);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> p[i][0] >> p[i][1];
    cout << maxPoints(p);
}
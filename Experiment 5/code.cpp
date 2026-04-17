#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    unordered_set<string> s;
    while (n--)
    {
        string x;
        cin >> x;
        s.insert(x);
    }
    while (m--)
    {
        string q;
        cin >> q;
        bool ok = false;
        for (int i = 0; i < q.size(); i++)
        {
            char old = q[i];
            for (char c = 'a'; c <= 'c'; c++)
            {
                if (c == old)
                    continue;
                q[i] = c;
                if (s.count(q))
                    ok = true;
            }
            q[i] = old;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long mod = 1e9 + 7, ans = 0;
    for (int b = 0; b < 32; b++)
    {
        long long c1 = 0;
        for (auto x : a)
            if (x & (1LL << b))
                c1++;
        long long c0 = n - c1;
        ans = (ans + (c1 * c0 % mod) * 2) % mod;
    }
    cout << ans;
}
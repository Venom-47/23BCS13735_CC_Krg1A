#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long l = a / gcd(a, b) * b;
    long long lo = 1, hi = 1e18, ans;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        long long cnt = mid / a + mid / b - mid / l;
        if (cnt >= n)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans % mod;
}
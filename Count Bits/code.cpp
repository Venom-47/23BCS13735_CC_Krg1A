#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ll mod = 1e9 + 7;

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    for (int b = 0; b < 32; b++) {
        ll one = 0;

        for (ll i = 0; i < n; i++) {
            if (a[i] & (1LL << b))
                one++;
        }

        ll zeroes = n - one;

        ans = (ans + ((one + zeroes) % mod) * 2) % mod;
    }

    cout << ans << endl;

    return 0;
}



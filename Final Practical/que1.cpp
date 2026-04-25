#include <bits/stdc++.h>
using namespace std;

long long computeHash(const string &s) {
    const int p = 31;              
    const int m = 1e9 + 7;        

    long long hash_value = 0;
    long long p_power = 1;

    for (char c : s) {
        int val = (c - 'a' + 1);  
        hash_value = (hash_value + val * p_power) % m;
        p_power = (p_power * p) % m;
    }

    return hash_value;
}

int main() {
    string s;
    cin >> s;
    
    cout << computeHash(s) << endl;
}

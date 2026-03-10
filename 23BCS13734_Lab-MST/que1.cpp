#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> tasks(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i][0] >> tasks[i][1];
    }

    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    });

    int ans = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr >= tasks[i][1])
            curr -= tasks[i][0];
        else
        {
            ans += tasks[i][1] - curr;
            curr = tasks[i][1] - tasks[i][0];
        }
    }

    cout << ans << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int triangularSum(vector<int> &nums)
{
    while (nums.size() > 1)
    {
        vector<int> v;
        for (int i = 0; i + 1 < nums.size(); i++)
            v.push_back((nums[i] + nums[i + 1]) % 10);
        nums = v;
    }
    return nums[0];
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << triangularSum(nums);
}
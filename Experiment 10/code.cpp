#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] += 1;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx);
        else
            update(2 * node + 1, mid + 1, end, idx);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);
    }
};

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    SegmentTree st(20001);

    for (int i = n - 1; i >= 0; i--) {
        int idx = nums[i] + 10000;

        result[i] = st.query(1, 0, 20000, 0, idx - 1);
        st.update(1, 0, 20000, idx);
    }

    return result;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);

    for (int x : res) cout << x << " ";
}

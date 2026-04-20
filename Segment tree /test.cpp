#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;



void build_tree(vector<int> &tree, vector<int> &arr ,int start, int end, int idx){
    
    if(start == end){
        tree[idx] = arr[start];
        return;
    }

    int mid = (start+end)/2;

    build_tree(tree,arr,start,mid,2*idx+1);
    build_tree(tree,arr,mid+1,end,2*idx+2);

    tree[idx] = max(tree[2*idx+1],tree[2*idx+2]);
}

void update(vector<int> &tree, vector<int> &lazy, int idx, int start, int end, int left, int right, int val) {

    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];

        if (start != end) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (right < start || left > end)
        return;

    if (left <= start && end <= right) {
        tree[idx] += val;

        if (start != end) {
            lazy[2*idx+1] += val;
            lazy[2*idx+2] += val;
        }
        return;
    }

    int mid = (start + end) / 2;

    update(tree, lazy, 2*idx+1, start, mid, left, right, val);
    update(tree, lazy, 2*idx+2, mid+1, end, left, right, val);

    tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
}

int query(vector<int>&tree, int idx, int start, int end, int left, int right){

    if(right < start || left > end){
        return INT_MIN;
    }

    if(start >= left && end <= right){
        return tree[idx];
    }

    int mid = (start+end)/2;

    int l = query(tree, 2*idx+1, start, mid, left, right);
    int r = query(tree, 2*idx+2, mid+1, end, left, right);

    return max(l,r);
}

int main() {

    vector<int> arr{1,2,3,4,5,6,7,8};
    vector<int> tree(40);

    vector<int> lazy(40);

    build_tree(tree, arr,0,7,0);

    for(auto i: tree) cout << i << " ";
    cout << endl;

    int min = query(tree, 0, 0, 7, 2, 5);

    cout << min << endl;
}
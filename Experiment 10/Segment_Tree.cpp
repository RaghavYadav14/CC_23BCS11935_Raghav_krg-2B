#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N], tree[4 * N];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);

    return p1 + p2;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << '\n';
        } else {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }
    }
}
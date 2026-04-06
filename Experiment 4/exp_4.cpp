#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int bit = 0; bit < 31; bit++) {
        long long ones = 0;
        for (int i = 0; i < n; i++)
            if ((a[i] >> bit) & 1) ones++;
        long long zeros = n - ones;
        ans = (ans + (ones % MOD) * (zeros % MOD) % MOD * 2) % MOD;
    }

    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const long long BASE1 = 131, BASE2 = 137;
const int MAXLEN = 600002;

long long pw1[MAXLEN], pw2[MAXLEN];

void precomputePowers() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < MAXLEN; i++) {
        pw1[i] = pw1[i-1] * BASE1 % MOD1;
        pw2[i] = pw2[i-1] * BASE2 % MOD2;
    }
}

pair<long long,long long> contextHash(const vector<long long>& ph1, const vector<long long>& ph2, int p, int len) {
    long long h1 = (ph1[p] * pw1[len-p-1] % MOD1 + ph1[len] - ph1[p+1] * pw1[len-p-1] % MOD1 + MOD1) % MOD1;
    long long h2 = (ph2[p] * pw2[len-p-1] % MOD2 + ph2[len] - ph2[p+1] * pw2[len-p-1] % MOD2 + MOD2) % MOD2;
    return {h1, h2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputePowers();

    int n, m;
    cin >> n >> m;


    unordered_map<int, vector<unordered_map<long long, set<char>>>> store;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.size();
        if (!store.count(len)) store[len].resize(len);

        vector<long long> ph1(len+1,0), ph2(len+1,0);
        for (int j = 0; j < len; j++) {
            ph1[j+1] = (ph1[j]*BASE1 + s[j]) % MOD1;
            ph2[j+1] = (ph2[j]*BASE2 + s[j]) % MOD2;
        }
        for (int p = 0; p < len; p++) {
            auto [h1, h2] = contextHash(ph1, ph2, p, len);
            long long key = h1 * MOD2 + h2;
            store[len][p][key].insert(s[p]);
        }
    }

    for (int q = 0; q < m; q++) {
        string s;
        cin >> s;
        int len = s.size();
        bool found = false;

        if (store.count(len)) {
            vector<long long> ph1(len+1,0), ph2(len+1,0);
            for (int j = 0; j < len; j++) {
                ph1[j+1] = (ph1[j]*BASE1 + s[j]) % MOD1;
                ph2[j+1] = (ph2[j]*BASE2 + s[j]) % MOD2;
            }
            for (int p = 0; p < len && !found; p++) {
                auto [h1, h2] = contextHash(ph1, ph2, p, len);
                long long key = h1 * MOD2 + h2;
                auto it = store[len][p].find(key);
                if (it != store[len][p].end()) {
                    const auto& chars = it->second;
                    // Check if there's a char different from s[p]
                    if (chars.size() > 1 || *chars.begin() != s[p])
                        found = true;
                }
            }
        }

        cout << (found ? "YES" : "NO") << "\n";
    }

    return 0;
}
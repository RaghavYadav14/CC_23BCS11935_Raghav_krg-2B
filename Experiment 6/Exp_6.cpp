#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<vector<bool>> added(26, vector<bool>(26, false));
    bool impossible = false;

    for (int i = 0; i + 1 < n; i++) {
        const string& a = names[i];
        const string& b = names[i+1];
        int len = min(a.size(), b.size());
        bool found = false;
        for (int j = 0; j < (int)len; j++) {
            if (a[j] != b[j]) {
                int u = a[j] - 'a', v = b[j] - 'a';
                if (!added[u][v]) {
                    added[u][v] = true;
                    adj[u].push_back(v);
                    indegree[v]++;
                }
                found = true;
                break;
            }
        }
        if (!found && a.size() > b.size()) {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        cout << "Impossible\n";
        return 0;
    }

  
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (indegree[i] == 0) q.push(i);

    string order = "";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order += (char)('a' + u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << order << "\n";
    }

    return 0;
}
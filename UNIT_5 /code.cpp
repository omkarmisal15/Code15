#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct SocialNetwork {
    int n;                       
    vector<string> names;         
    vector<vector<int> > adj;     
};


int findUser(const SocialNetwork &g, const string &name) {
    for (int i = 0; i < g.n; i++)
        if (g.names[i] == name) return i;
    return -1;
}

void addFriendship(SocialNetwork &g, int u, int v) {
    g.adj[u].push_back(v);
    g.adj[v].push_back(u);
}


void bfs(const SocialNetwork &g, int start) {
    vector<bool> visited(g.n, false);
    vector<int> level(g.n, -1);
    queue<int> q;

    visited[start] = true;
    level[start] = 0;
    q.push(start);

    cout << "\nBFS exploration order from " << g.names[start] << ":\n";
    int step = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << step++ << ". " << g.names[u]
             << (level[u] == 0 ? " (selected user)"
                               : " (connection level " + to_string(level[u]) + ")")
             << "\n";

        for (size_t i = 0; i < g.adj[u].size(); i++) {
            int v = g.adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    // Users not reachable from the selected user
    bool any = false;
    for (int i = 0; i < g.n; i++) {
        if (!visited[i]) {
            if (!any) { cout << "\nNot connected to " << g.names[start] << ":\n"; any = true; }
            cout << " - " << g.names[i] << "\n";
        }
    }
}

int main() {
    SocialNetwork g;

    cout << "Enter number of users: ";
    cin >> g.n;
    if (g.n <= 0) {
        cout << "Invalid number of users.\n";
        return 1;
    }

    g.names.resize(g.n);
    g.adj.assign(g.n, vector<int>());

    cout << "Enter " << g.n << " user names (no spaces):\n";
    for (int i = 0; i < g.n; i++) cin >> g.names[i];

    int m;
    cout << "Enter number of friendships: ";
    cin >> m;
    cout << "Enter each friendship as two names (e.g. Alice Bob):\n";
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        int u = findUser(g, a), v = findUser(g, b);
        if (u == -1 || v == -1) {
            cout << "Unknown user, skipping this pair.\n";
            continue;
        }
        addFriendship(g, u, v);
    }

    string startName;
    cout << "Enter the selected user: ";
    cin >> startName;
    int start = findUser(g, startName);
    if (start == -1) {
        cout << "User not found.\n";
        return 1;
    }

    bfs(g, start);
    return 0;
}

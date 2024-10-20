#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    vector<long long int> parent;  // stores the parent of each element
    vector<long long int> rank;    // stores the rank (approximate depth) of each element

public:
    // Constructor: initialize the parent and rank arrays
    UnionFind(long long int n) {
        parent.resize(n);
        rank.resize(n, 0);  // initially, all elements have rank 0
        for (long long int i = 0; i < n; ++i) {
            parent[i] = i;  // each element is its own parent (self-leader)
        }
    }

    // Find the representative of the set that contains element x
    long long int find(long long int x) {
        if (parent[x] != x) {
            // Path compression: make x polong long int directly to the root
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union: merge the sets containing elements x and y
    void unionSets(long long int x, long long int y) {
        long long int rootX = find(x);
        long long int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;  // rootX becomes the parent of rootY
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;  // rootY becomes the parent of rootX
            } else {
                parent[rootY] = rootX;  // make rootX the parent of rootY
                rank[rootX]++;          // increase the rank of rootX
            }
        }
    }

    // Check if two elements are in the same set
    bool isConnected(long long int x, long long int y) {
        return find(x) == find(y);
    }
};

void solve() {
    long long int n, m;
    cin >> n >> m;
    UnionFind u(n+1);
    for (long long int i = 0; i < m; i++) {
        long long int a, d, k;
        cin >> a >> d >> k;
        for (long long int j = 1; j <= k; j++) {
            u.unionSets(a, a+(j*d));
        }
    }
    set<long long int> s(u.parent.begin(), u.parent.end());
    cout << s.size() - 1<< endl;
}

int main() {
    long long int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

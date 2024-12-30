#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

const long long MOD = 1000000008;

#define all(c) (c).begin(), (c).end()

#define forn(i, a, b) for (int i = a; i < b; ++i)

#define pb push_back
#define mp make_pair
const int MAX_NODES = 100000;
std::vector<int> disjointSet[MAX_NODES];
int parent[MAX_NODES];

void init_set(int v) {
    disjointSet[v] = {v};
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (disjointSet[a].size() < disjointSet[b].size()) swap(a, b);
        for (int v : disjointSet[b]) {
            parent[v] = a;
            disjointSet[a].pb(v);
        }
        disjointSet[b].clear();
    }
}

std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<int> bitResult(200100, 0);
std::vector<bool> visited;
int nodes, edges;

int dfs(int v) {
    visited[v] = true;
    int subtree_size = 1;
    for (auto& neighbor : graph[v]) {
        if (visited[neighbor.first]) continue;

        long long subtree_count = dfs(neighbor.first);
        subtree_size += subtree_count;

        long long product = subtree_count * (nodes - subtree_count);
        int index = neighbor.second;
        while (product > 0) {
            if (product % 2) bitResult[index]++;
            product /= 2;
            if (bitResult[index] == 2) {
                bitResult[index] = 0;
                product++;
            }
            index++;
        }
    }
    return subtree_size;
}

int main() {
    std::vector<std::pair<int, std::pair<int, int>>> edgeList;
    scanf("%d %d", &nodes, &edges);

    forn(i, 0, edges) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        edgeList.pb(mp(weight, mp(u - 1, v - 1)));
    }

    graph.resize(nodes);
    forn(i, 0, nodes) init_set(i);
    sort(all(edgeList));

    for (auto& edge : edgeList) {
        int u = edge.second.first;
        int v = edge.second.second;
        int root_u = find_set(u);
        int root_v = find_set(v);

        if (root_u == root_v) continue;
        int weight = edge.first;
        graph[u].pb(mp(v, weight));
        graph[v].pb(mp(u, weight));
        union_sets(u, v);
    }

    visited = std::vector<bool>(nodes, false);
    dfs(0);

    while (bitResult.back() == 0) bitResult.pop_back();
    reverse(all(bitResult));
    for (auto val : bitResult) printf("%d", val);

    return 0;
}

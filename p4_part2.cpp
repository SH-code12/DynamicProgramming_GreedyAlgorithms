#include <iostream>

#include <algorithm>
#include <vector>


using namespace std;

const int MAX_NODES = 50005;
const long long INFINITY = 0x3f3f3f3f3f3f3f3fLL;

struct Edge {
    int start, end;
    long long goldCost, silverCost;
};

int numNodes, numEdges, goldMultiplier, silverMultiplier;
long long minimumCost;
vector<Edge> edges, selectedEdges;
vector<int> parent;

int findParent(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}

void initializeDisjointSet() {
    for (int i = 1; i <= numNodes; ++i)
        parent[i] = i;
}

bool compareEdges(const Edge& a, const Edge& b) {
    if (a.goldCost != b.goldCost)
        return a.goldCost < b.goldCost;
    return a.silverCost < b.silverCost;
}

void computeMinimumCost() {
    minimumCost = INFINITY;
    for (size_t i = 0; i < edges.size(); ++i) {
        initializeDisjointSet();
        selectedEdges.push_back(edges[i]);

        sort(selectedEdges.begin(), selectedEdges.end(),
             [](const Edge& a, const Edge& b) { return a.silverCost < b.silverCost; });

        int connectedComponents = 0;
        long long maxSilverCost = -INFINITY;

        vector<Edge> validEdges;
        for (const auto& edge : selectedEdges) {
            int rootA = findParent(edge.start);
            int rootB = findParent(edge.end);

            if (rootA != rootB) {
                maxSilverCost = max(maxSilverCost, edge.silverCost);
                validEdges.push_back(edge);
                parent[rootA] = rootB;
                connectedComponents++;
            }
            if (connectedComponents == numNodes - 1)
                break;
        }

        if (connectedComponents == numNodes - 1) {
            long long currentCost =
                    edges[i].goldCost * goldMultiplier + maxSilverCost * silverMultiplier;
            minimumCost = min(minimumCost, currentCost);
        }

        selectedEdges = validEdges;
    }
}

int main() {
    cin >> numNodes >> numEdges;
    cin >> goldMultiplier >> silverMultiplier;

    edges.resize(numEdges);
    parent.resize(numNodes + 1);

    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].start >> edges[i].end >> edges[i].goldCost >> edges[i].silverCost;
    }

    sort(edges.begin(), edges.end(), compareEdges);
    computeMinimumCost();

    if (minimumCost == INFINITY)
        cout << "-1\n";
    else
        cout << minimumCost << "\n";

    return 0;
}

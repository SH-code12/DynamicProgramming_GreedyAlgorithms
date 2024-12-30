// Shahd Elnassag
// question 3 in Part 2 Greedy algorithm and MST

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathExists(int numOfNodes, vector<vector<int>>& edges, int startNode, int targetNode) {
        unordered_map<int, vector<int>> adjacencyList;

        // Building the adjacency list
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        vector<bool> isVisited(numOfNodes, false);
        queue<int> nodes;
        nodes.push(startNode);
        isVisited[startNode] = true;

        int currentNode;

        // check if a path exists from startNode to targetNode
        while (!nodes.empty()) {
            currentNode = nodes.front();
            nodes.pop();

            if (currentNode == targetNode) {
                return true;
            }

            // Explore all neighbors
            for (auto &neighbor : adjacencyList[currentNode]) {
                if (!isVisited[neighbor]) {
                    isVisited[neighbor] = true;
                    nodes.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int startN1 = 0, targetN1 = 2;
    bool res1 = sol.isPathExists(n1, edges1, startN1, targetN1);
    cout << (res1 ? "true" : "false") << "\n";

    // Test 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int startN2 = 0, targetN2 = 5;
    bool result2 = sol.isPathExists(n2, edges2, startN2, targetN2);
    cout << (result2 ? "true" : "false") << "\n";

    return 0;
}

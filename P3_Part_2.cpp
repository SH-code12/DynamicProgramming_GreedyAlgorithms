// Created by Shahd Elnassag on 12/29/2024.
// Problem 3 in Part 2 Greedy algorithm and MST

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathExists(int nodeCount, vector<vector<int>>& edges, int startNode, int targetNode) {
        unordered_map<int, vector<int>> adjacencyList;

        // Building the adjacency list
        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(nodeCount, false);
        queue<int> nodesQueue;
        nodesQueue.push(startNode);
        visited[startNode] = true;

        int currentNode;

        // check if a path exists from startNode to targetNode
        while (!nodesQueue.empty()) {
            currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode == targetNode) {
                return true;  // Path found
            }

            // Explore all neighbors
            for (auto &neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
        }

        return false;  // No path found
    }
};

int main() {
    Solution solution;

    // Test case 1
    int nodeCount1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int startNode1 = 0, targetNode1 = 2;
    bool result1 = solution.isPathExists(nodeCount1, edges1, startNode1, targetNode1);
    cout << (result1 ? "true" : "false") << "\n";

    // Test case 2
    int nodeCount2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int startNode2 = 0, targetNode2 = 5;
    bool result2 = solution.isPathExists(nodeCount2, edges2, startNode2, targetNode2);
    cout << (result2 ? "true" : "false") << "\n";

    return 0;
}

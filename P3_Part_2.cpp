// Created by Shahd Elnassag on 12/29/2024.
// Problem 3 in Part 2 Greedy algorithm and MST

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    bool isPathExists(int numOfNodes, vector<vector<int>>& edges, int firstNode, int targetNode) {
        unordered_map<int, vector<int>> graph;

        // Building the adjacency list
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numOfNodes, false);
        queue<int> nodesQueue;
        nodesQueue.push(firstNode);
        visited[firstNode] = true;

        int currentNode;

        // check if a path exists from firstNode to targetNode
        while (!nodesQueue.empty()) {
            currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode == targetNode) {
                return true;  // Path found
            }

            // Explore all neighbors
            for (auto &nextNode : graph[currentNode]) {
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    nodesQueue.push(nextNode);
                }
            }
        }

        return false;
    }
};

int main() {
    Graph graph;

    // Test case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int startNode1 = 0, targetNode1 = 2;
    bool result1 = graph.isPathExists(n1, edges1, startNode1, targetNode1);
    cout << (result1 ? "true" : "false") << "\n";

    // Test case 2
    int nodeCount2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int startNode2 = 0, targetNode2 = 5;
    bool result2 = graph.isPathExists(nodeCount2, edges2, startNode2, targetNode2);
    cout << (result2 ? "true" : "false") << "\n";

    return 0;
}

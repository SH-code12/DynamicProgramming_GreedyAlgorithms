#include <bits/stdc++.h>
// Created by Shahd Elnassag on 12/29/2024.
// Problem 5 in Part 1 Dynamic Programming

using namespace std;

// Function to find the length of the Longest Increasing Subsequence
int findLongestIncreasingSubsequence(int numElements, vector<int>& sequence) {
    vector<int> subsequence;

    for (int i = 0; i < numElements; ++i) {
        // Find the position where sequence[i] can replace an element in subsequence using binary search
        auto it = lower_bound(subsequence.begin(), subsequence.end(), sequence[i]);

        // If sequence[i] is greater than all elements in subsequence, append it
        if (it == subsequence.end()) {
            subsequence.push_back(sequence[i]);
        } else {
            // Replace the element at the found position with sequence[i]
            *it = sequence[i];
        }
    }

    // The size of the subsequence array will be the length of the longest increasing subsequence
    return subsequence.size();
}

int main() {
    // Input
    int numElements;
    cin >> numElements;
    vector<int> sequence(numElements);

    for (int i = 0; i < numElements; ++i) {
        cin >> sequence[i];
    }

    // Find the length of the longest increasing subsequence
    int longestLength = findLongestIncreasingSubsequence(numElements, sequence);

    // Output the result
    cout << longestLength << endl;

    return 0;
}

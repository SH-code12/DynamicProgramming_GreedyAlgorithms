#include <bits/stdc++.h>
// Created by Shahd Elnassag on 12/29/2024.
// Problem 5 in Part 1 Dynamic Programming

using namespace std;

int main() {
    // test
    int num;
    cin >> num;
    vector<int> givenSequence(num);
    for (int i = 0; i < num; ++i) {
        cin >> givenSequence[i];
    }
    vector <int> dp(num,1);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < i; ++j) {
            if (givenSequence[i] > givenSequence[j]){
                dp[i] = max(dp[i] , 1 + dp[j]);
            }
        }

    }
    int result = *max_element(dp.begin(),dp.end());
    cout << result << endl;

    return 0;
}
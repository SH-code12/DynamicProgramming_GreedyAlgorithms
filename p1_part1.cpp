#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> fairDivision(int n, std::vector<std::pair<int, std::vector<int>>> &problems) {
    std::vector<int> results;

    for (int i = 0; i < n; ++i) {
        int m = problems[i].first;
        std::vector<int> coin = problems[i].second;

        int totalSum = accumulate(coin.begin(), coin.end(), 0);
        int halfSum = totalSum / 2;

        std::vector<bool> dp(halfSum + 1, false);
        dp[0] = true;

        for (int coins : coin) {
            for (int j = halfSum; j >= coins; --j) {
                dp[j] = dp[j] || dp[j - coins];
            }
        }

        int closestSum = 0;
        for (int j = halfSum; j >= 0; --j) {
            if (dp[j]) {
                closestSum = j;
                break;
            }
        }

        int min_diff = totalSum - 2 * closestSum;
        results.push_back(min_diff);
    }

    return results;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, std::vector<int>>> problems(n);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        std::vector<int> coins(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> coins[j];
        }
        problems[i] = {m, coins};
    }

    std::vector<int> results = fairDivision(n, problems);

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

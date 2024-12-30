#include <vector>
#include <algorithm>

class Solution {
public:
    bool canDivideSubset(std::vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return false;
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;

        std::sort(nums.begin(), nums.end());
        int row = nums.size() - 1;

        if (nums[row] > target) {
            return false;
        }

        return canDivide(nums, row, target, k);
    }

private:
    bool canDivide(std::vector<int>& nums, int row, int target, int k) {
        if (k == 1) {
            return true;
        }

        while (row >= 0 && nums[row] == target) {
            row--;
            k--;
        }

        for (int i = row; i >= 0; i--) {
            if (nums[i] > target) {
                continue;
            }

            if (canDivide(nums, i - 1, target - nums[i], k - 1)) {
                return true;
            }

            while (i > 0 && nums[i] == nums[i - 1]) {
                i--;
            }
        }
        return false;
    }
};

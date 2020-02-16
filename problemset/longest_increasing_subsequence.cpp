#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// classic dp
class ClassicDPSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len_nums = nums.size();
        if (len_nums == 0) {
            return 0;
        }
        vector<int> dp(len_nums);
        for (int i = 0; i < len_nums; i++) {
            dp[i] = 1;
        }
        for (int i = 1; i < len_nums; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// dp with binary search
class BinarySearchDPSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        vector<int> dp;
        for (auto& num : nums) {
            // update the smallest digit that's the end of sequence of length idx
            // lower_bound: https://www.cnblogs.com/Tang-tangt/p/9291018.html
            auto idx = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            if (idx >= dp.size()) {
                dp.emplace_back(num);
            } else {
                dp[idx] = num;
            }
        }
        return dp.size();
    }
};

int main() {
    BinarySearchDPSolution sol;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    int res;
    res = sol.lengthOfLIS(nums);
    cout << res << endl;
}
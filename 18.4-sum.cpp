/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        if (nums.empty()) return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int target_2 = target - nums[i] - nums[j];

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    int two_sum = nums[left] + nums[right];
                   
                    if (two_sum < target_2) ++left;

                    else if (two_sum > target_2) --right;
                    
                    else {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);

                        while (left < right && nums[left] == quad[2]) ++left;
                        while (left < right && nums[right] == quad[3]) --right;

                    }
                }
                while (j + 1 < n && nums[j+1] == nums[j]) ++j;
            }
            while (i + 1 < n && nums[i+1] == nums[i]) ++i;
        } 
        return res;
    }
};
// @lc code=end


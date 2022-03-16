/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.empty()) return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; ++i) {
                int target = 0 - nums[i];

                int left = i + 1;
                int right = n - 1;

                while (left < right) {
                    int two_sum = nums[left] + nums[right];
                   
                    if (two_sum < target) ++left;

                    else if (two_sum > target) --right;
                    
                    else {
                        vector<int> triplet(3,0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[left];
                        triplet[2] = nums[right];
                        res.push_back(triplet);

                        while (left < right && nums[left] == triplet[1]) ++left;
                        while (left < right && nums[right] == triplet[2]) --right;

                    }
                }
           
            while (i + 1 < n && nums[i+1] == nums[i]) ++i;
        } 
        return res;
    }
};
// @lc code=end


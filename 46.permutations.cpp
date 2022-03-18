/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    void recurPermute(int index, int &n, vector<int> &nums, vector<vector<int>> &ans) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < n; ++i) {
            swap(nums[index], nums[i]);
            recurPermute(index+1, n, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        recurPermute(0, n, nums, ans);
        return ans;

    }
};
// @lc code=end


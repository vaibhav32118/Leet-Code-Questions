/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:    
    bool swapCheck(vector<int> &nums, int &start,int &curr) {
        for(int i = start;i < curr; ++i) {
            if (nums[i] == nums[curr]) {
                return false;
            }
        }
        return true;
    }

public:
    void recurPermuteUnique(int index, int &n, vector<int> &nums, vector<vector<int>> &ans) {
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < n; ++i) {
            bool check = swapCheck(nums,index,i);
            if (check) {
                swap(nums[index], nums[i]);
                recurPermuteUnique(index+1, n, nums, ans);
                swap(nums[index], nums[i]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
       
        recurPermuteUnique(0, n, nums, ans);
        return ans;

    }
};
// @lc code=end


class Solution {
private:
    int solve(vector<int>& nums, int target,int sum,int ind) {
        if(sum == target && ind == nums.size()) return 1;
        if(ind >= nums.size()) return 0;
        int add = solve(nums,target,sum + nums[ind],ind+1);
        int sub = solve(nums,target,sum - nums[ind],ind+1);
        return add + sub;
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};

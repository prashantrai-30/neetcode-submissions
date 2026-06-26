class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i = 0;i < n;i++) {
            int ind = abs(nums[i]);
            if(ind <= nums.size() && ind >= 1){
                if(nums[ind-1] > 0)nums[ind-1] *= -1;
                else if(nums[ind-1] == 0) nums[ind-1] = -1 * (ind+1);
            }
        }
        int i = 1;
        while(i <= nums.size()) {
            if(nums[i-1] >= 0) return i;
            i++;
        }
        return nums.size()+1;
    

    }
};
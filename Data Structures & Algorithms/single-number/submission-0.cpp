class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            int cnt = 0;
            for(int j = 0;j < n;j++) {
                if(nums[j] == nums[i] && i != j) cnt++;
            }
            if(cnt == 0) return nums[i]; 
        }
        return -1;
    }
};

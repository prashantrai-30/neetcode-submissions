class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int x : nums) st.insert(x);
        for(int i = 0;i < n+1;i++) {
            if(st.count(i) == 0) return i;
        }
        return -1;
    }
};

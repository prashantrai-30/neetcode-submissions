class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        unordered_set<int>st;
        int r = 0,l = 0;
        while(r < n) {
            while(r-l > k) {
                st.erase(nums[l]);
                l++;
            }
            if(st.find(nums[r]) != st.end()) return true;
            st.insert(nums[r]);
            r++;
        }
        return false;
    }
};
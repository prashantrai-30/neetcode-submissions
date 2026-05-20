class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,r = 0;
        int maxi = 0;
        unordered_map<int,int>mp;
        while(r < s.size()) {
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            maxi = max(maxi,r-l+1);
            mp[s[r]] = r;
            r++;
        }
        return maxi;
    }
};

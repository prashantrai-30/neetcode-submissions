class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(n < m) return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i = 0;i < m;i++) v1[s1[i] - 'a']++;
        for(int j = 0;j < m;j++) v2[s2[j] - 'a']++;
        int l = 0,r = m;
        while(r < n) {
            if(v1 == v2) return true;
            v2[s2[l] - 'a']--;
            l++;
            v2[s2[r] - 'a']++;
            r++;
        }
        return v1 == v2;
    }
};

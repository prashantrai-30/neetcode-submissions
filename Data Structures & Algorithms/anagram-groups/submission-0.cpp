class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(auto x : strs) {
            string temp = x;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(x);
        }
        for(auto it : mpp) ans.push_back(it.second);
        return ans;
    }
};

class Solution {
private:
    int countSetBit(int i) {
        int res = 0;
        while(i) {
            i = i & (i-1);
            res++;
        }
        return res;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0;i <= n;i++) {
            int res = countSetBit(i);
            ans.push_back(res);
        }
        return ans;
    }
};

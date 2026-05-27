class Solution {
private:
    int solve(int ind,vector<int>&cost,vector<int>&dp) {
        if(ind >= cost.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int onestep = cost[ind] + solve(ind+1,cost,dp);
        int twostep = cost[ind] + solve(ind+2,cost,dp);
        return dp[ind] = min(onestep,twostep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};

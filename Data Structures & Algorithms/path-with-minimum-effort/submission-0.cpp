class Solution {
private:
    bool isvalid(int x,int y,int m,int n) {
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        int dx[] = {0,1,0,-1};
        int dy[] = {-1,0,1,0};
        while(!pq.empty()) {
            auto it = pq.top();
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();
            for(int i = 0;i < 4;i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(isvalid(newx,newy,m,n)){
                    int neweffort = max(dist,abs(heights[newx][newy] - heights[x][y]));
                    if(neweffort < dis[newx][newy]) {
                        dis[newx][newy] = neweffort;
                        pq.push({neweffort,{newx,newy}});
                    }
                }  
            }
        }
        return dis[m-1][n-1];
    }
};
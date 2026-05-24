class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        vector<int>time(n+1,1e9);
        time[k] = 0;
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        pq.push({0,k});
        while(!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            for(auto it : adj[node]) {
                int adjnode = it.first;
                int w = it.second;
                int newwt = w + wt;
                if(newwt < time[adjnode]) {
                    time[adjnode] = newwt;
                    pq.push({newwt,adjnode});
                }
            }
        }
        int ans = *max_element(time.begin() + 1,time.end());
        return ans == 1e9 ? -1 : ans;
    }
};

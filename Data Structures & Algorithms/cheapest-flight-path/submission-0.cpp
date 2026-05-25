class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>cost(n,1e9);
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        cost[src] = 0;
        pq.push({0,{0,src}});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int node = it.second.second;
            int wt = it.second.first;
            if(stops > k) continue;
            for(auto it : adj[node]) {
                int adjnode = it.first;
                int w = it.second;
                int newwt = w + wt;
                if(newwt < cost[adjnode] && stops <= k) {
                    cost[adjnode] = newwt;
                    pq.push({stops+1,{newwt,adjnode}});
                }
            }
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];

    }
};

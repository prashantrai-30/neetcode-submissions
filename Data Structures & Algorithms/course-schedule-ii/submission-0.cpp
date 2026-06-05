class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,stack<int>&st,vector<int>&vis,vector<int>&pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto nbr : adj[node]) {
            if(pathVis[nbr]) return true;
            if(!vis[nbr]) 
            {
                if(dfs(nbr,adj,st,vis,pathVis)) return true;
            }
        }
        st.push(node);
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        stack<int>st;
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        bool cycle = false;
        for(auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        for(int i = 0;i < numCourses;i++) {
            if(!vis[i]) 
            {
                if(dfs(i,adj,st,vis,pathVis)) cycle = true;
            }
        }
        if(cycle) return {};
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

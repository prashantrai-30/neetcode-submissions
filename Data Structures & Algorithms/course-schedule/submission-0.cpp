class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>topo;
        for(auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        for(int i = 0;i < adj.size();i++) {
            for(auto j : adj[i]) indegree[j]++;
        }
        for(int i = 0;i < numCourses;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        return (topo.size() == numCourses);
    }
};

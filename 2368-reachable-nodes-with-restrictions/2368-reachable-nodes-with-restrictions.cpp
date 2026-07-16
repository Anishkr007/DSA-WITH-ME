class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&ban,vector<vector<int>>&adj,int &count){
        vis[node]=1;
        count++;

        for(auto next:adj[node]){
            if(ban[next]) continue;
            if(!vis[next]){
                dfs(next,vis,ban,adj,count);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<int>vis(n,0);

        vector<int>ban(n,0);

        for(auto x: restricted){
            ban[x]=1;
        }

        vector<vector<int>>adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

        }


       int count=0;

        dfs(0,vis,ban,adj,count);

        return count;

    }
};
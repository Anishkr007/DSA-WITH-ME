class Solution {
public:
    bool dfs(int source,int destination,vector<vector<int>>&adj,vector<int>& vis){
        
        vis[source]=1;

        for(auto next: adj[source]){
            if(next==destination) return true;

            if(!vis[next]){

                if(dfs(next,destination,adj,vis)){
                    return true;
                }
            }
        }

        return false;


    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;

        vector<int>vis(n,0);
        vector<vector<int>> adj(n);

            for(auto &e : edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

        return dfs(source,destination,adj,vis);
    }
};
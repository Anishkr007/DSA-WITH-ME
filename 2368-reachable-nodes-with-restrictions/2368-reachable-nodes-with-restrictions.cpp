class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
         vector<vector<int>>adj(n);
        for(auto & e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
       

        vector<int>ban(n,0);
        vector<int>vis(n,0);

        for(auto node : restricted){
            ban[node]=1;
        }

        queue<int>q;
        q.push(0);

        vis[0]=1;
        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            count++;

            for(auto next:adj[node]){
                if(ban[next]) continue;

                if(!vis[next]){
                    vis[next]=1;
                    q.push(next);
                    

                }
            }
        }

        return count;


    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto &e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dist(n,1e9);
        dist[src]=0;
    // stops,node,cost
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

         while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node=it.second.first;
        int cost=it.second.second;

        if(stops>k) continue;

        for(auto nbr: adj[node]){
            int wt=nbr.second;
            int adjNode=nbr.first;

            if(wt+cost<dist[adjNode]&&stops<=k){
                dist[adjNode]=wt+cost;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }

        }
    }
    if(dist[dst]==1e9) return -1;

    return dist[dst];

    }

   
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(auto &e:flights) adj[e[0]].push_back({e[1],e[2]});
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops=it.first;
            int currNode=it.second.first;
            int currDist=it.second.second;

            if(stops>k) continue;

            for(auto nbr : adj[currNode]){
                int nextNode=nbr.first;
                int wt =nbr.second;

                if(currDist+wt<dist[nextNode]){
                    dist[nextNode]=currDist+wt;
                    q.push({stops+1,{nextNode,currDist+wt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;

        return dist[dst];
        
    }
};
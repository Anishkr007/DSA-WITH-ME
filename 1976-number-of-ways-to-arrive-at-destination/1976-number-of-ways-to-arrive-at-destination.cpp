class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto & e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});

        }
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        //{wt,Node}

        pq.push({0,0});
        int mod = 1e9+7;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currTime=it.first;
            long long currNode=it.second;

            if(currTime>dist[currNode]) continue;

            for(auto nbr : adj[currNode]){
                long long nextNode=nbr.first;
                long long time=nbr.second;

                if(time+currTime<dist[nextNode]){
                    dist[nextNode]=time+currTime;
                    ways[nextNode]=ways[currNode];
                    pq.push({dist[nextNode],nextNode});
                }
                else if(time+currTime==dist[nextNode]){
                    ways[nextNode]=(ways[nextNode]+ways[currNode])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
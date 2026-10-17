class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>>adj(V);

        vector<int>indegree(V);

        for(auto &e : prerequisites){
            int u=e[0];
            int v=e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            cnt++;

            for(auto next : adj[node]){
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }

        return cnt==V;
    }
};
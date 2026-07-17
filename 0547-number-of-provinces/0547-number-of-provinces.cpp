class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[node]=1;

        for(int next=0;next<isConnected.size();next++){
            if(vis[next]!=1 && isConnected[node][next]==1){
                dfs(next,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();

        vector<int> vis(n,0);

        int provinces=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                provinces++;
            }
        }

        return provinces;
    }
};
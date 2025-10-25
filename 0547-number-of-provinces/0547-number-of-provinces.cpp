class Solution {
public:
    void DFS(int node,vector<vector<int>>& isConnected,vector<int>& vis){
        vis[node]=1;
        int n=isConnected.size();
        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[node][j]){
                DFS(j,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){

                DFS(i,isConnected,vis);
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:

void dfs(int start,vector<vector<int>>& adjLs,vector<int>& vis){
    vis[start]=1;
    for(auto it: adjLs[start]){
        if(!vis[it]){
        dfs(it,adjLs,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
       int V=isConnected.size();
         vector<vector<int>> adjLs(V);

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> vis(V,0);
        int cnt=0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }
};
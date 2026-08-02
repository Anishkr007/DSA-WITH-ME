class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<int> front=grid[n-1];

        for(int i=n-2;i>=0;i--){

            vector<int> curr(n);

            for(int j=0;j<n;j++){

                int best=1e9;

                for(int k=0;k<n;k++){

                    if(k!=j)
                        best=min(best,front[k]);
                }

                curr[j]=grid[i][j]+best;
            }

            front=curr;
        }

        int ans=1e9;

        for(int x:front)
            ans=min(ans,x);

        return ans;
    }
};
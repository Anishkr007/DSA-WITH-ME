class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int total=0;

        for(auto x : stones){
            total+=x;
        }

        int n=stones.size();

        vector<vector<bool>>dp(n+1,vector<bool>(total+1,false));


        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=total;j++){
                bool ntake=dp[i-1][j];

                bool take=false;

                if(stones[i-1]<=j){
                    take=dp[i-1][j-stones[i-1]];
                }

                dp[i][j]=take||ntake;
            }
        }

        int ans=INT_MAX;

        for(int s1=0;s1<=total/2;s1++){

            if(dp[n][s1]){
            ans=min(ans,total-s1*2);
            }
        }

        return ans;
    }
};
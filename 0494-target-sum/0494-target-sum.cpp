class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        int n=nums.size();

        for(auto x : nums){
            total+=x;
        }
        

        if((target + total) % 2 != 0){
            return 0;
        }


        if(total<abs(target)) return 0;
        int sum=(total+target)/2;
    

        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                int nottake=dp[i-1][j];

                int take=0;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }

                dp[i][j]=take+nottake;
            }
        }

        return dp[n][sum];
    }
};
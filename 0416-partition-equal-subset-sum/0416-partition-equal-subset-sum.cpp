class Solution {
public:
    bool f(vector<int>& nums,int s){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(s+1,false));
        //base case 0
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        // nums[0]<sum
        if(nums[0]<=s){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                bool nottake=dp[i-1][j];
                bool take = false;
                if(nums[i]<j){
                    take=dp[i-1][j-nums[i]];

                }
                dp[i][j]=(take||nottake);
            }
        }
        return dp[n-1][s];
    } 
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2==1) return false;

        return f(nums,sum/2);
    }
};
class Solution {
public:
    int solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(i==0){
            if(nums[i]==0 && target==0) return 2;

            if(nums[i]==target || target==0) return 1;

            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int nottake=solve(i-1,target,nums,dp);
        int take=0;
        if(nums[i]<=target){
            take=solve(i-1,target-nums[i],nums,dp);
        }

        return dp[i][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();

        for(int x : nums){
            sum+=x;
        }

        if(abs(target)>sum) return 0;

        int newtarget=(sum+target)/2;

        if(((sum+target)%2)!=0) return 0;
        vector<vector<int>>dp(n,vector<int>(newtarget+1,-1));

        return solve(n-1,newtarget,nums,dp);
    }
};
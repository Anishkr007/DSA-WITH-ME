class Solution {
public:
    int solve(int i,vector<int>& arr,int k,vector<int>&dp){
        int n=arr.size();

        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi=INT_MIN;
        int len=0;
        int maxSum=INT_MIN;

        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(arr[j],maxi);
            int sum=(len*maxi)+solve(j+1,arr,k,dp);
            maxSum=max(maxSum,sum);

        }
        return dp[i]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        
        return solve(0,arr,k,dp);
    }
};
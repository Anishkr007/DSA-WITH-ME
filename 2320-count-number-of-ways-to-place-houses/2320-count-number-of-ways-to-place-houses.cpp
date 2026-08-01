class Solution {
public:
    long long mod=1e9+7;
    long long solve(int n,vector<long long>&dp){

        if(n==1) return 2;
        if(n==2) return 3;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;

    }
    int countHousePlacements(int n) {

        if(n==1) return 4;
vector<long long>dp(n+1,-1);

        
        long long ans=solve(n,dp)%mod;

        return (ans*ans)%mod;
    }
};
class Solution {
public:
int f(vector<int>& nums,int start,int end){
    int n = -start+end+1;

    vector<int>dp(n);
    dp[0]=nums[start];
    if(n==1) return nums[start];
    dp[1]=max(nums[start],nums[start+1]);

    for(int i=2;i<n;i++){
        dp[i]=max(nums[start+i]+dp[i-2],dp[i-1]);

    }
    return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        int leave_first=f(nums,1,n-1);
        int leave_last = f(nums,0,n-2);

        return max(leave_first,leave_last);
    }
};
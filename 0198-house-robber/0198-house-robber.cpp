class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1) return nums[0];

        

        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        
        int ans=0;
        for(int i=2;i<n;i++){
            int take=nums[i]+prev2;

            int nottake=prev1;


            ans=max(take,nottake);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
};
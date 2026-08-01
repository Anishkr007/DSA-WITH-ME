class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        if(n==1) return nums[0];

        int prev1=max(nums[0],nums[1]);
        int prev2=nums[0];
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
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int>arr1;
        vector<int>arr2;

        for(int i=0;i<n;i++){
            if(i!=n-1){
                arr1.push_back(nums[i]);
            }
            if(i!=0){
                arr2.push_back(nums[i]);
            }
        }

        return max(solve(arr1),solve(arr2));
    }
};
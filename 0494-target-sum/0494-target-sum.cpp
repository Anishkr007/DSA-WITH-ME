class Solution {
public:
    int solve(int i,int target,vector<int>& nums){
        if(i==0){
            if(nums[i]==0 && target==0) return 2;

            if(nums[i]==target || target==0) return 1;

            return 0;
        }

        int nottake=solve(i-1,target,nums);
        int take=0;
        if(nums[i]<=target){
            take=solve(i-1,target-nums[i],nums);
        }

        return take+nottake;
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

        return solve(n-1,newtarget,nums);
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            maxsum=max(nums[i],maxsum+nums[i]);
            ans=max(ans,maxsum);
        }

        return ans;
    }
};
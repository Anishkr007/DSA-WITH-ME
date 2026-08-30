class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int ans=INT_MIN;
        int left=0;

        for(int right=0;right<nums.size();right++){
            sum+=nums[right];

            if((right-left+1)>k){
                sum-=nums[left];
                left++;

            }

            if((right-left+1)==k){
                ans=max(ans,sum);
            }
        }

        return double(ans)/k;
    }
};
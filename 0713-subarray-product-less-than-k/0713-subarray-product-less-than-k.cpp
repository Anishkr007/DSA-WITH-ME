class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int left=0;
        int ans=0;
        long long pro=1;

        if(k<=1) return 0;

        for(int right=0;right<nums.size();right++){
            pro=pro*nums[right];

            while(pro>=k){
                pro/=nums[left];
                left++;
            }

            if(pro<k){
                ans+=right-left+1;
            }
        }

        return ans;
    }
};
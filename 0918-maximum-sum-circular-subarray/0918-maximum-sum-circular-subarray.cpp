class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int currmax=0;
        int currmin=0;

        int maxsum=nums[0];
        int minsum=nums[0];

        int total=0;

        for(auto x : nums){
            total+=x;

            currmax=max(x,currmax+x);
            maxsum=max(maxsum,currmax);

            currmin=min(x,currmin+x);
            minsum=min(minsum,currmin);
        }

        if(maxsum<0) return maxsum;

        return max(maxsum,total-minsum);
    }
};
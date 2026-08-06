class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax=0;
        int currmin=0;

        int maxsum=nums[0];
        int minsum=nums[0];

        for(auto x : nums){
            currmin=min(x,x+currmin);
            minsum=min(currmin,minsum);

            currmax=max(x,x+currmax);
            maxsum=max(currmax,maxsum);
        }


        return max(maxsum,abs(minsum));
    }
};
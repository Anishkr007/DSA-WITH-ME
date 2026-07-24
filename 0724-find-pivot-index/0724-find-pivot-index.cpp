class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();

        int sum=0;
        int left=0;

        for(int x: nums){
            sum+=x;
        }
        for(int i=0;i<n;i++){
            int rsum=sum-nums[i]-left;

            if(left==rsum) return i;

            left+=nums[i];
        }

        return -1;
    }
};
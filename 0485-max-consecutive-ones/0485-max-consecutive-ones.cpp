class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int one=0;
        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                one++;
            }
            maxi=max(maxi,one);

            if(nums[i]==0){
                one=0;
            }

        }
        return maxi;
    }
};
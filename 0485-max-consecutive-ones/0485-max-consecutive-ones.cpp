class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();

        int ccount=0;
        int scount=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1) {
                ccount++;
                scount=max(scount,ccount);
            }
        
            else{
                ccount=0;
            }
        

        }
        return scount;
    }
};
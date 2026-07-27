class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

       int left=0;
       int sum=0;
        for(int x : nums){
            sum+=x;
        }
       int n=nums.size();

       for(int i=0;i<n;i++){
        int rightsum=sum-nums[i]-left;

        if(rightsum==left){
            return i;
        }

        left+=nums[i];
       } 

       return -1;
    }
};
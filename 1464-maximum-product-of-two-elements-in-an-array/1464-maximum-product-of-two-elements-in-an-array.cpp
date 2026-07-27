class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int first=0;
        int second=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=first){
                second=first;
                first=nums[i];
                
            }else if(nums[i]>second){
                second=nums[i];
            }
        }

        int ans=(first-1)*(second-1);

        return ans;
    }
};
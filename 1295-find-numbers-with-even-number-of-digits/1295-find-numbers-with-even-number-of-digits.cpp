class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        long ans=0;
        long count=0;

        for(int i=0;i<nums.size();i++){
            while(nums[i]>0){
                nums[i]/=10;
                count++;
            }
            if(count%2==0){
                ans++;
            }

            count=0;
        }

        return ans;
    }
};
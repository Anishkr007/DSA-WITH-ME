class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;

        for(auto x : nums){
            if(x!=0){
            ans.push_back(x);

            }
        }

         while(ans.size() < nums.size()){
            ans.push_back(0);
        }

        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
        

        
    }
};
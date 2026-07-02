class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>max_jump) return false;

            max_jump=max(max_jump,i+nums[i]);
        }

        return true;
    }
};
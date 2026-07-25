class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n+1,0);

        for(int i=0;i<nums.size();i++){
            vis[nums[i]]++;
        }

        for(int i=0;i<=nums.size();i++){
            if(vis[i]==0){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int currSum=0;
        mp[0]=-1;
        int result =0;
        for(int i=0;i<n;i++){
            currSum+=(nums[i]==0)?-1:1;

            if(mp.count(currSum)){
                result=max(result,i-mp[currSum]);
            }else{
                mp[currSum]=i;
            }
        }
        return result;
    }
};
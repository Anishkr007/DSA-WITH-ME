class Solution {
public:
int Atmost(vector<int>&nums,int k){
    int left=0;
    int n=nums.size();
    int ans=0;

    unordered_map<int,int>mp;

    for(int right=0;right<n;right++){
        mp[nums[right]]++;

        while(mp.size()>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                mp.erase(nums[left]);
                
            }
            left++;
        }

        ans+=right-left+1;
    }

    return ans;

}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Atmost(nums,k)-Atmost(nums,k-1);
    }
};
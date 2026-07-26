class Solution {
public:
int Atmost(vector<int>& nums,int goal){
    int left=0;
    long long sum=0;
    int ans=0;
    if(goal<0) return 0;

    for(int right=0;right<nums.size();right++){
        sum+=nums[right];

        while(sum>goal){
            sum-=nums[left];
            left++;
        }

        ans+=right-left+1;
    }

    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Atmost(nums,goal)-Atmost(nums,goal-1);


    }
};
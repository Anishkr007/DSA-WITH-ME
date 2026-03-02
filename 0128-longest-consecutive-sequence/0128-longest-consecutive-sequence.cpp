class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s(nums.begin(),nums.end());
        int ans=0;
        for(int i : s){
            if(!s.count(i-1)){
                int curr=i;
                int count=1;
                while(s.count(curr+1)){
                    curr++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
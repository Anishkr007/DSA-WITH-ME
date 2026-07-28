class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int prefix=0;
        map<int,int>mp;
        mp[0]=1;

        int ans=0;

        for(auto x: nums){
            prefix+=x;

            int rem=prefix%k;

            if(rem<0){
                rem+=k;
            }

            if(mp.count(rem)){
                ans+=mp[rem];
            }

            mp[rem]++;
        }
        return ans;
    }
};
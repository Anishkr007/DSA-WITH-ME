class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total = 0;

        for(int x : nums)
            total += x;

        int need = total % p;

        if(need == 0)
            return 0;

        unordered_map<int,int> mp;

        mp[0] = -1;

        long long prefix = 0;

        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];

            int rem = prefix % p;

            int target = (rem - need + p) % p;

            if(mp.count(target))
            {
                ans = min(ans, i - mp[target]);
            }

            mp[rem] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
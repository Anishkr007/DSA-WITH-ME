class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0;
        int prefix=0;

        map<int,int>mp;

        mp[0]=1;

        for(int i =0;i<nums.size();i++){
            prefix+=nums[i];

            int remove=prefix-k;

            count+=mp[remove];

            mp[prefix]+=1;
        }

        return count;
    }
};
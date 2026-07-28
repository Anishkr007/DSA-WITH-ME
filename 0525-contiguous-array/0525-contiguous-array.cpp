class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                temp[i]=-1;
            }else{
                temp[i]=nums[i];
            }
        }

        int prefix=0;
        int ans=0;

        map<int,int>mp;
        mp[0]=-1;

        int k=0;

        for(int i=0;i<n;i++){
            prefix+=temp[i];

            if(mp.count(prefix-k)){
                ans=max(ans,i-mp[prefix-k]);
            }
            if(!mp.count(prefix)){
                mp[prefix]=i;
            }
        }

        return ans;

    }
};
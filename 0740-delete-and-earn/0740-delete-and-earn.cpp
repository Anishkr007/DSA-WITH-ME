class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>arr(mx+1,0);
        for(auto x : nums){
            arr[x]+=x;
        }

        if(mx==0) return arr[0];

        int prev1=max(arr[0],arr[1]);
        int prev2=arr[0];
        int ans=0;
        for(int i=2;i<arr.size();i++)
        {
            int take=arr[i]+prev2;
            int nottake=prev1;

            ans=max(take,nottake);

            prev2=prev1;
            prev1=ans;


        }

        return prev1;
    }
};
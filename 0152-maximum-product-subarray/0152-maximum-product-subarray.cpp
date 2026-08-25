class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int minProd=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int maxi=maxProd;
            int mini=minProd;

            maxProd=max({nums[i],maxi*nums[i],mini*nums[i]});
            minProd=min({nums[i],maxi*nums[i],mini*nums[i]});

            ans=max(maxProd,ans);
        }

        return ans;
    }
};
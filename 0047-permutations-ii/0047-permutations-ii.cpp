class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,vector<int>&vis){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;

            if(i>0 && nums[i-1]==nums[i] && !vis[i-1]){
                continue;
            }

            vis[i]=1;

            ds.push_back(nums[i]);

            solve(nums,ans,ds,vis);

            ds.pop_back();

            vis[i]=0;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;

        vector<int>vis(nums.size(),0);

        sort(nums.begin(),nums.end());

        solve(nums,ans,ds,vis);

        return ans;
    }
};
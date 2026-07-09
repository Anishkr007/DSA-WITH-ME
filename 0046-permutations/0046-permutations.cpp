class Solution {
public:
    void solve(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,vector<int>&vis){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i=0;i<nums.size();i++){

            if(vis[i]) continue;

            vis[i]=1;
            ds.push_back(nums[i]);

            solve(nums,ds,ans,vis);
            ds.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int> ds;
    int n=nums.size();
    vector<vector<int>>ans;

    vector<int>vis(n,0);

    solve(nums,ds,ans,vis);

    return ans;
    }
};
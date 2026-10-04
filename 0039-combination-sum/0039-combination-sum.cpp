class Solution {
public:

    void solve(int start,vector<int>& candidates, int target,vector<int>ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(target<0){
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) break;

            ds.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        vector<int>ds;
        vector<vector<int>>ans;

        solve(0,candidates,target,ds,ans);

        return ans;
    }
};
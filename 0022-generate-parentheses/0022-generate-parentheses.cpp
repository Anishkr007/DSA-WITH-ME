class Solution {
public:
    void solve(int open,int close,vector<string>&ans,string &ds,int n){
        if(ds.size()==2*n){
            ans.push_back(ds);
            return;
        }

        if(open<n){
            ds.push_back('(');
            solve(open+1,close,ans,ds,n);
            ds.pop_back();
        }

        if(close<open){
            ds.push_back(')');
            solve(open,close+1,ans,ds,n);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds="";

        solve(0,0,ans,ds,n);

        return ans;
    }
};
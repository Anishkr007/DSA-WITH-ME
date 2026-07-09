class Solution {
public:
    void solve(int i,vector<string>&ans,string& ds,vector<string>&mp,string &digits){
        if(ds.size()==digits.size()){
            ans.push_back(ds);
            return;
        }

        int num=digits[i]-'0';

        for(char ch : mp[num]){
            ds.push_back(ch);
            solve(i+1,ans,ds,mp,digits);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

       vector<string>ans;
       string ds="";
        if(digits.empty())
            return ans;
       vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

       solve(0,ans,ds,mp,digits); 

       return ans;
    }
};
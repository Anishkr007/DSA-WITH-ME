class Solution {
public:
static bool cmp(pair<char,int>& a,pair<char,int>&b){
    return a.second>b.second;
}
    string frequencySort(string s) {
        unordered_map<char,int>mp;

        for(auto c : s){
            mp[c]++;
        }

        vector<pair<char,int>> vec;

        for(auto x : mp ){
            vec.push_back(x);
        }

        sort(vec.begin(),vec.end(),cmp);

        string ans="";

        for(auto x: vec){
            ans+=string(x.second,x.first);
        }

        return ans;
    }
};
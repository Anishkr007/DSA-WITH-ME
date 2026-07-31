class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;

        for(auto x : matches){
            mp[x[0]]+=0;
            mp[x[1]]++;
        }

        vector<int> zero,first;

        for(auto x : mp){
            if(x.second==0){
                zero.push_back(x.first);

            }else if(x.second==1){
                first.push_back(x.first);
            }
        }

        return {zero,first};
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        map<int,int> loss;

        for(auto &x : matches){
            loss[x[0]] += 0;
            loss[x[1]]++;
        }

        vector<int> zero, one;

        for(auto &x : loss){
            if(x.second == 0)
                zero.push_back(x.first);
            else if(x.second == 1)
                one.push_back(x.first);
        }

        return {zero, one};
    }
};
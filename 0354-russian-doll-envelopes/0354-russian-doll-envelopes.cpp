class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),
        [](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }

            return a[0]<b[0];
        });
        vector<int>temp;
        for(auto &e : envelopes){
            int h=e[1];
            

            int pos=lower_bound(temp.begin(),temp.end(),h)-temp.begin();

            if(pos==temp.size()){
                temp.push_back(h);
            }else{
                temp[pos]=h;
            }
        }

        return temp.size();
    }
};
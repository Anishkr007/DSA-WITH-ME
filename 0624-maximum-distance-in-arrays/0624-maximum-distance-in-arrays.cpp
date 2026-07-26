class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();

        int ans=0;

        for(int i=1;i<arrays.size();i++){

            int currmin=arrays[i][0];
            int currmax=arrays[i].back();

            ans=max(ans,currmax-mini);
            ans=max(ans,maxi-currmin);

            mini=min(mini,currmin);
            maxi=max(maxi,currmax);





        }
        return ans;
    }
};
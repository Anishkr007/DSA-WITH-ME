class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0,curr=0;
        for(int g : gain){
            curr+=g;
            mx=max(curr,mx);
        }
        return mx;
    }
};
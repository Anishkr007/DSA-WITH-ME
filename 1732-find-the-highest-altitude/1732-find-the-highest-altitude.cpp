class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maxi=0;
        int n=gain.size();
        vector<int>peak(n+1);

        peak[0]=0;

        for(int i=1;i<=n;i++){
            peak[i]=peak[i-1]+gain[i-1];

            maxi=max(maxi,peak[i]);
        }
        return maxi;
    }
};
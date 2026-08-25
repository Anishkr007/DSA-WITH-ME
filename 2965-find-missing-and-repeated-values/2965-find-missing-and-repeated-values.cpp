class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int total=n*n;

        vector<int>freq(total+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        int rep=-1;
        int miss=-1;
        for(int i=1;i<total+1;i++){
            if(freq[i]==0){
                miss=i;
            }

            if(freq[i]==2){
                rep=i;
            }

        }

        return {rep,miss};
    }
};
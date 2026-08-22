class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
                return a[1]>b[1];
        });

        int total=0;
        for(auto box : boxTypes){
            int pieces=min(truckSize,box[0]);
            total+=pieces*box[1];

            truckSize-=pieces;

            if(truckSize==0) break;

        }

        return total;
    }
};
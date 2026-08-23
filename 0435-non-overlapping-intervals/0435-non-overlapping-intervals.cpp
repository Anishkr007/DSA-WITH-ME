class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });

    
        int end=INT_MIN;
        int count=0;

        for(auto val : intervals){
            int starttime=val[0];
            int endtime=val[1];

            if(starttime>=end){
                count++;
                end=endtime;
            }
            
        }

        return n-count;

    }
};
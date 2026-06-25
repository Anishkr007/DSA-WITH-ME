class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n),pge(n);
        vector<int> nse(n),pse(n);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            pse[i]=st.empty()?-1:st.top();

            st.push(i);

        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            nse[i]=st.empty()?n:st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

         for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            pge[i]=st.empty()?-1:st.top();

            st.push(i);

        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();

            nge[i]=st.empty()?n:st.top();

            st.push(i);
        }
        
        long long leftmax=0;
        long long rightmax=0;
        long long leftmin=0;
        long long rightmin=0;

        long long totalleft=0;
        long long totalright=0;
        for(int i=0;i<n;i++){

            leftmin=i-pse[i];
            rightmin=nse[i]-i;

            totalleft+=leftmin*rightmin*nums[i]*1LL;

            leftmax=i-pge[i];
            rightmax=nge[i]-i;

            totalright+=leftmax*rightmax*nums[i]*1LL;




        }

        return totalright-totalleft;
    }
};
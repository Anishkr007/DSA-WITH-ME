class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;

        for(auto x : st){
            if(st.find(x-1)==st.end()){
                int curr=x;
                int len=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;


                }

                ans=max(ans,len);
            }
        }

        return ans;
    }
};
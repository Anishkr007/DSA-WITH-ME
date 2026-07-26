class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=INT_MIN;
        unordered_set<char>st;
        if(s.size()==0) return 0;

        for(int right=0;right<s.size();right++){

            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            ans=max(ans,right-left+1);
        }

        return ans;
    }
};
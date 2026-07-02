class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;

        for(char ch='a';ch<='z';ch++){
            int l = s.find(ch);
            int r=s.rfind(ch);

            if(l!=string::npos && r-l>1){
                unordered_set<char>st;

                for(int i=l+1;i<r;i++){
                    st.insert(s[i]);

                }
                ans+=st.size();
            }
        }
        return ans;
    }
};
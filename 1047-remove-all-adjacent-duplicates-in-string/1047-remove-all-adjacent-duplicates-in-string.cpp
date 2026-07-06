class Solution {
public:
    string removeDuplicates(string s) {
        string st="";

        for(auto c : s){
            if(!st.empty()&&st.back()==c) st.pop_back();
            else{
                st.push_back(c);
            }
        }
        return st;
    }
};
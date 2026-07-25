class Solution {
public:

    string build(string s){

        stack<char> st;

        for(char c : s){

            if(c == '#'){
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(c);
            }
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool backspaceCompare(string s, string t) {

        return build(s) == build(t);
    }
};
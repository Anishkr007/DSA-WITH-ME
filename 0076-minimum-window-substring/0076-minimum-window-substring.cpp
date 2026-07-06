class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp;

        for(char c : t)
            mp[c]++;

        int need = t.size();

        int l = 0;
        int r = 0;

        int start = 0;
        int mn = INT_MAX;

        int n = s.size();

        while(r < n){

            if(mp[s[r]] > 0)
                need--;

            mp[s[r]]--;

            while(need == 0){

                if(r-l+1 < mn){
                    mn = r-l+1;
                    start = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                    need++;

                l++;
            }

            r++;
        }

        if(mn == INT_MAX)
            return "";

        return s.substr(start,mn);
    }
};
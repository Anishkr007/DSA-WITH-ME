class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;

        for(auto c: t){
            mp[c]++;

        }

        int need=t.size();

        int r=0,l=0,start=0;
        int mn=INT_MAX;

        while(r<s.size()){
            if(mp[s[r]]>0) need--;

            mp[s[r]]--;

            while(need==0){
                if(r-l+1<mn){
                    mn=r-l+1;
                    start=l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0) need++;

                l++;
            }
            r++;
        }

        if(mn==INT_MAX) return "";
        return s.substr(start,mn);
    }
};
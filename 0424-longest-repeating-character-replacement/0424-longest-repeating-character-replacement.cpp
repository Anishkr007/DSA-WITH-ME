class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;

        unordered_map<int,int>mp;
        int ans=0;
        int maxfreq=0;
        int n=s.size();

        while(r<n){
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]);

            while(r-l+1-maxfreq>k){
                mp[s[l]]--;
                l++;
            }

            ans=max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};
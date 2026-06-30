class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;

        unordered_map<char,int>mp;
        int maxfreq=0;
        int ans=0;

        while(j<s.size()){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);

            while((j-i+1)-maxfreq>k){
                mp[s[i]]--;
                i++;
            }

            ans=max(ans,j-i+1);

            j++;
        }

        return ans;
    }
};
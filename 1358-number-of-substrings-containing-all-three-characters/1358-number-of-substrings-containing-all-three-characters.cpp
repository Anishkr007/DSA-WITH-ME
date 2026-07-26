class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,int>mp;
        int n=s.size();

        for(int right=0;right<s.size();right++){
            mp[s[right]]++;

            while(mp['a']>0 && mp['b'] && mp['c']){
                ans+=n-right;

                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};
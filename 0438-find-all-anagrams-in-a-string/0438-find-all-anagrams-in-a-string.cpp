class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freqP(26,0);
        vector<int>freqS(26,0);

        for(auto x : p){
            freqP[x-'a']++;
        }

        int k=p.size();
        int left=0;

        vector<int>ans;

        for(int right=0;right<s.size();right++){
            freqS[s[right]-'a']++;

            if(right-left+1>k){
                freqS[s[left]-'a']--;
                left++;

            }
            if(right-left+1==k){
                if(freqS==freqP){
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};
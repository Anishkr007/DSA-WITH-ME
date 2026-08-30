class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        int n=s.size();
        vector<int>ans;

        vector<int> freqs(26,0);
        vector<int> freqp(26,0);

        int left=0;

        for(auto c : p){
            freqp[c-'a']++;
        }

        for(int right=0;right<n;right++){
            freqs[s[right]-'a']++;

            if(right-left+1==k){
                if(freqs==freqp){
                    ans.push_back(left);
                }

                freqs[s[left]-'a']--;
                left++;
            }
        }

        return ans;
    }
};
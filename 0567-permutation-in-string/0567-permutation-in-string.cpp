class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int p=s1.size();
        int n=s2.size();

        vector<int>freqs1(26,0);
        vector<int>freqs2(26,0);

        for(auto c : s1){
            freqs1[c-'a']++;
        }
        int left=0;

        for(int right=0;right<n;right++){

            freqs2[s2[right]-'a']++;
            if(right-left+1==p){
                if(freqs1==freqs2){
                 return true;
                }

                freqs2[s2[left]-'a']--;
            left++;
            }

            



        }
        return false;


    }
};

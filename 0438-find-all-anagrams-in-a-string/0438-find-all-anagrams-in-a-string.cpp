class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>window(26,0);
        vector<int>need(26,0);

        for( auto x : p){
            need[x-'a']++;
        } 

        if(s.size()<p.size()){
            return ans;
        }

        int left=0;
        int k=p.size();

        for(int right=0;right<s.size();right++){

            window[s[right]-'a']++;

            if((right-left+1)==k){

                if(need==window){
                    ans.push_back(left);
                }

                window[s[left]-'a']--;
                left++;

            }
        }

        return ans;
    }
};
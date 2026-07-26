class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0;
        int maxfreq=0;
        int ans=0;
        unordered_map<char,int>mp;

        for(int right=0;right<answerKey.size();right++){
            mp[answerKey[right]]++;
            maxfreq=max(maxfreq,mp[answerKey[right]]);

            while(right-left+1-maxfreq>k){
                mp[answerKey[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
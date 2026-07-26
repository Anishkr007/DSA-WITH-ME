class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0;
        int ans=0;
        int cnt=0;
        for(int right=0;right<s.size();right++){

            if(s[right]=='a' ||s[right]=='e' ||s[right]=='i' ||s[right]=='o' ||s[right]=='u' ){
                cnt++;
                
            }

            if(right-left+1>k){
                if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'){
                    cnt--;
                }

                left++;
            }
            
            if(right-left+1==k){
                ans=max(ans,cnt);
            }

        }
        return ans;
    }
};
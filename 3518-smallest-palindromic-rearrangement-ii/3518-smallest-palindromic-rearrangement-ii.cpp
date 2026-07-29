class Solution {
public:
    #define ll long long 
    ll NCR(int n , int r){
        if(r>n-r)r=n-r;
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/i;
            if(ans>1e11)return 1e11;
        }
       return ans; 
    }

    ll BS(vector<int>&freq){
        int tot=accumulate(freq.begin(),freq.end(),0LL);
        long long ans=1;
        for(auto cnt:freq){
            if(cnt>0){
                ll cs = NCR(tot,cnt);
                if(ans>(1e11/cs))return 1e11;
                ans*=cs;
                tot-=cnt;
            }
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        k=k-1;
        vector<int>freq(26,0);
        for(auto c:s)freq[c-'a']++;
        for(int i=0;i<26;i++){
            freq[i]>>=1;
        }
        int len = accumulate(freq.begin(),freq.end(),0LL);
        if(k>=BS(freq))return "";
        string ans="";
        for(int i=0;i<len;i++){
            for(int c=0;c<26;c++){
                if(freq[c]>0){
                    freq[c]--;
                    long long sz=BS(freq);
                    if(k>=sz){
                        k-=sz;
                        freq[c]++;
                    }else{
                        ans+=char(c+'a');
                        break;
                    }
                }
            }
        }
        string rev=ans;
        reverse(ans.begin(),ans.end());
        if(s.size()&1){
            rev+=s[(s.size()/2)];
        }
        return rev+ans;
    }
};
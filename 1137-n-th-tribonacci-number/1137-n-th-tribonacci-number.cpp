class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;

        int prev3=0;
        int prev2=1;
        int prev1=1;
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=prev3+prev2+prev1;
            prev3=prev2;
            prev2=prev1;
            prev1=ans;
        }

        return prev1;
    }
};
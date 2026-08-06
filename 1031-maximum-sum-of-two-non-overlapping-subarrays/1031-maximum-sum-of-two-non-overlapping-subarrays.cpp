class Solution {
public:
    int solve(vector<int>& nums, int L, int M ){
        int n=nums.size();
        vector<int>prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        int bestL=0;
        int ans=0;

        for(int i=L+M;i<=n;i++){
            int currentL=prefix[i-M]-prefix[i-M-L];

            bestL=max(bestL,currentL);

            int currentM=prefix[i]-prefix[i-M];
            ans=max(ans,currentM+bestL);
        }

        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums,firstLen,secondLen),solve(nums,secondLen,firstLen));
    }
};
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i + firstLen - 1 < n; i++) {

            int sum1 = 0;

            for (int k = i; k < i + firstLen; k++)
                sum1 += nums[k];

            for (int j = 0; j + secondLen - 1 < n; j++) {

                if (j + secondLen - 1 < i || j > i + firstLen - 1) {

                    int sum2 = 0;

                    for (int k = j; k < j + secondLen; k++)
                        sum2 += nums[k];

                    ans = max(ans, sum1 + sum2);
                }
            }
        }

        return ans;
    }
};
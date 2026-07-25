class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        int left=0;
        int right=n-1;
        int idx=n-1;

        while(left<=right){
            int leftsquare=nums[left]*nums[left];
            int rightsquare=nums[right]*nums[right];
            if(leftsquare>rightsquare){
                ans[idx]=leftsquare;
                left++;
                idx--;
            }else{
                ans[idx]=rightsquare;
                right--;
                idx--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left=0;
        int count=0;
        int sum=0;
        for(int right=0;right<arr.size();right++){
            sum+=arr[right];

            if(right-left+1>k){
                sum-=arr[left];
                left++;
            }
            if(right-left+1==k){
                if((sum/k)>=threshold){
                    count++;
                }
            }
        }
        return count;
    }
};
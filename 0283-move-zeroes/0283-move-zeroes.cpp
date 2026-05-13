class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = -1;

        // Find first zero
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        // No zero present
        if(j == -1) return;

        // Move non-zero elements forward
        for(int i = j + 1; i < nums.size(); i++) {

            if(nums[i] != 0) {

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // Farthest index we can reach so far
        
        for (int i = 0; i < nums.size(); i++) {
            // If current index is beyond what we can reach, we fail
            if (i > maxReach) return false;
            
            // Update the farthest index we can reach
            maxReach = max(maxReach, i + nums[i]);
        }
        
        // If loop finishes, we can reach the end
        return true;
    }
};

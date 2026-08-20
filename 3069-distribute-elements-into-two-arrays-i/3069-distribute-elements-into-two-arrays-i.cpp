class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1={nums[0]};
        vector<int> temp2={nums[1]};

        for(int i=2;i<n;i++){
            if(temp1.back()>temp2.back()){
                temp1.push_back(nums[i]);
            }else{
                temp2.push_back(nums[i]);
            }
        }

        for(auto x : temp2){
            temp1.push_back(x);
        }

        return temp1;
        
    }
};
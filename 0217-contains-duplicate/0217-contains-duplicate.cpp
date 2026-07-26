class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool>mp;

        for(auto x : nums){
            if(mp[x]==false){
                mp[x]=true;
            }else{
                return true;
            }
        }
        return false;
    }
};
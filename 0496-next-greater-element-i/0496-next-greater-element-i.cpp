class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;

        int n=nums2.size();
        stack<int>st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }

            mp[nums2[i]]=st.empty()?-1:st.top();

            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x : nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};
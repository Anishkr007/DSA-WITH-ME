/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>mp;
    int pre=0;

    TreeNode* build(vector<int>& preorder,int left,int right){
        if(left>right) return NULL;

        int val=preorder[pre];
        pre++;

        TreeNode* node=new TreeNode(val);

        int mid=mp[val];

        node->left=build(preorder,left,mid-1);
        node->right=build(preorder,mid+1,right);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return build(preorder,0,inorder.size()-1);
    }
};
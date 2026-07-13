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
    bool sum(TreeNode* root, int targetSum,int ans){
        if(root==NULL) return false;

        ans+=root->val;

        if(root->left==NULL && root->right==NULL){
            return ans==targetSum;
        }

        return sum(root->left,targetSum,ans)||sum(root->right,targetSum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         

        return sum(root,targetSum,0);        
    }
};
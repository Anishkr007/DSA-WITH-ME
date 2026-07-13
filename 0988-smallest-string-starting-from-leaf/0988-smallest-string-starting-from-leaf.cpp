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
string ans="~";
    void dfs(TreeNode* root,string path){
        if(root==NULL) return;

        path=char(root->val+'a')+path;

        if(root->right==NULL && root->left==NULL){
            ans=min(ans,path);
            return;
        }

        dfs(root->left,path);
        dfs(root->right,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        vector<long long> levelSum;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            long long sum = 0;

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            levelSum.push_back(sum);
        }

        root->val = 0;

        queue<pair<TreeNode*, int>> qq;
        qq.push({root, 0});

        while (!qq.empty()) {

            auto [node, level] = qq.front();
            qq.pop();

            long long childSum = 0;

            if (node->left)
                childSum += node->left->val;

            if (node->right)
                childSum += node->right->val;

            if (node->left) {
                node->left->val = levelSum[level + 1] - childSum;
                qq.push({node->left, level + 1});
            }

            if (node->right) {
                node->right->val = levelSum[level + 1] - childSum;
                qq.push({node->right, level + 1});
            }
        }

        return root;
    }
};
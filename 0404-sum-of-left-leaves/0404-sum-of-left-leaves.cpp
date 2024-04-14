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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left and !node->left->left and !node->left->right) {
                sum += node->left->val;
            }
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right); 
        }
        return sum;
    }
};
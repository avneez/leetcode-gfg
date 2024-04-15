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
    string sum = "";
    int ans = 0;
    // vector<int> v;
    void dfs(TreeNode* root, string digit) {
        if (!root) return;
        digit += to_string(root->val);
        if (!root->left && !root->right){
            sum+=digit;
            ans += (stoi(sum));
        }
        dfs(root->left, digit);
        dfs(root->right, digit);
        sum="";
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root,"");
        // for(auto i:v) ans+=i;
        return ans;
    }
};
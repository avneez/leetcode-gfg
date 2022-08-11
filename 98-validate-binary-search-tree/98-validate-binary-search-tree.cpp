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

//using recursion for taking max values
// class Solution {
// public:
//     bool helper(TreeNode* root,long low ,long high){
//         // Empty trees are valid BSTs.
//         if(root == NULL)
//             return true;
        
//         if((root->val < high) && (root->val > low)){
//           return (helper(root->left, low, root->val) && helper(root->right, root->val, high));
//         }
        
//         return false;
//     }
    
//     bool isValidBST(TreeNode* root) {
//         return helper(root, LONG_MIN, LONG_MAX);
//     }
// };

//using inorder traversal as it is sorted in the array
class Solution {
public:
    void helper(TreeNode* root, vector<int> & ans){
        if(root==NULL  ) return;
        helper(root->left, ans);
        ans.push_back(root->val);
         helper(root->right, ans);
     
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
       for(int i=0; i<ans.size()-1; i++){
           if( ans[i]>= ans[i+1] ) return false;
        }
        return true;
    }
};
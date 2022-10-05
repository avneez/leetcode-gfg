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

//BFS solution
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return new TreeNode(val);
        if(depth==1){
            TreeNode* ans=new TreeNode(val);
            ans->left=root;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(l<depth-2){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            l++;
        }
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* ans1=new TreeNode(val);
            TreeNode* ans2=new TreeNode(val);
            TreeNode* p=curr->left;
            TreeNode* q=curr->right;
            curr->left=ans1;
            curr->right=ans2;
            ans1->left=p;
            ans2->right=q;
        }
        return root;
    }
};

//DFS solution

// dfs approach => maintain a present height varaible and when the height becomes equal to the
//depth, then, add two nodes with value val to the left and right of the node at that particular depth.


// class Solution {
// public:
//     TreeNode * helper(TreeNode * root, int val, int depth, int present){
//         // return null when we reach a null node
//         if (root == NULL){
//             return NULL;
//         }
                  
//         if (present == depth - 1){
//             TreeNode * left = new TreeNode(val);
//             left->left = root->left;
//             TreeNode * right = new TreeNode(val);
//             right->right = root->right;
//             root->left = left;
//             root->right = right;
//             return root;
//         }else{
//             root->left = helper(root->left, val, depth, present + 1);
//             root->right = helper(root->right, val, depth, present + 1);
//             return root;
//         }
//     }
    
//     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
//         // takes care of the condition when root is at the specified depth
        
//         if (depth == 1){
//             TreeNode * newroot = new TreeNode(val);
//             newroot->left = root;
//             return newroot;
//         }
//         return helper(root, val, depth, 1);
//     }
// };
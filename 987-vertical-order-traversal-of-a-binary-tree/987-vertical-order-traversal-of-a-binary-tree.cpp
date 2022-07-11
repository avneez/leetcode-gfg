// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     void getvert(TreeNode* root,int hd, map<int,vector<int>>&mp){
//         if(!root) return;
//         mp[hd].push_back(root->val);
//         getvert(root->left,hd-1,mp);
//         getvert(root->right,hd+1,mp);
//     }
    
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         if(!root) return{};
//         vector<vector<int>> ans;
//         vector<int> v;
//         map<int,vector<int>> mp;
//         getvert(root, 0, mp); 
                
// //         queue<pair<TreeNode*,int>> q;
// //         q.push({root,0});
// //         while(!q.empty()){
// //             auto nodehd = q.front();
// //             TreeNode* node = nodehd.first;
// //             int hd = nodehd.second;
// //             q.pop();
// //             mp[hd].push_back(node->val);
            
// //             if(node->left) q.push({node->left, hd-1});
// //             if(node->right) q.push({node->right, hd+1});
// //         }
        
//         for(auto p=mp){
//             for(){
//                v.insert(v.end(), j.begin(), j.end());
//             }
//             ans.push_back(v);
//             v.clear();
//         }
//         return ans;       
//     }
// };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;

        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        todo.push({root, {0, 0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }
        }

        for(auto &p : nodes){
            vector<int> col;
            for(auto &q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
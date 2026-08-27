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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mp;
        mp[nullptr] = {0, 0};
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* node = stk.top();

            if(node->left && mp.find(node->left) == mp.end()){
                stk.push(node->left);
            } 
            else if(node->right && mp.find(node->right) == mp.end()){
                stk.push(node->right);
            } else{
                node = stk.top(); stk.pop();

                auto[leftHeight, leftDia] = mp[node->left];
                auto[rightHeight, rightDia] = mp[node->right];

                int height = 1 + max(leftHeight, rightHeight);
                int dia = max(leftHeight+rightHeight, 
                            max(leftDia, rightDia));

                mp[node] = {height, dia};
            }
        }

        return mp[root].second;
        
    }
};

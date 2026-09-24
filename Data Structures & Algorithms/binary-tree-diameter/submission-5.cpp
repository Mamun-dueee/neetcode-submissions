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
        if(root == nullptr) return 0;
        int dia = height(root->left) + height(root->right);
        int maxChildDia = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(dia, maxChildDia);
        
    }

    int height(TreeNode* node)
    {
        if(!node) return 0;
        return 1+max(height(node->left), height(node->right));
    }
};

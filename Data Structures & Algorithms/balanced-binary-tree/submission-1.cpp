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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int leftHeight = H(root->left);
        int rightHeight = H(root->right);
        cout << leftHeight << " " << rightHeight << endl; 
        if(abs(leftHeight - rightHeight) <= 1 
            && isBalanced(root->left) 
            && isBalanced(root->right)){
            return true;
        }
        else{
            return false;
        }
        
    }
    int H(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(H(root->left), H(root->right));
    }
};

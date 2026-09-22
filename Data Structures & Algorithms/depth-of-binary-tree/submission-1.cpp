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

//BFS approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q; 
        if(root) q.push(root);

        //traverse level-by-level
        int depth = 0;
        while(!q.empty())
        {
            depth++;
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* curNode = q.front(); q.pop();

                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
        }
        return depth;
        
    }
};

/* depth = 2, 
q = 2, 3


*/

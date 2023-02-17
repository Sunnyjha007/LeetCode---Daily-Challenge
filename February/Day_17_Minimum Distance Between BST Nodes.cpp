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
     int ans = INT_MAX;
    TreeNode* prev = NULL;
    void solve(TreeNode* root){
        if(root->left)solve(root->left);
        if(prev)ans = min(ans,root->val-prev->val);
        prev=root;
        if(root->right)solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
       solve(root);
        return ans;   
    }
};

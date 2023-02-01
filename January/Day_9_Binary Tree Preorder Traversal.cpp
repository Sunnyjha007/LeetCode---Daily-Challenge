class Solution {
public:
void  solve(TreeNode* root,vector<int>& v){
        if(!root)return;
        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> v;
        solve(root,v);
        return v;
    }
};

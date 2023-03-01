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
   string inorder(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& res){
        if(!root)return "";
        string left = inorder(root->left,mp,res);
        string right = inorder(root->right,mp,res);
        string ans = "(" +  left + " " +  to_string(root->val) + " "  + right + ")";
        if(mp[ans]==1)res.push_back(root);
        mp[ans]++;
        return ans; 
}
    
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
	unordered_map<string, int> mp;
	vector<TreeNode*> res;
	inorder(root, mp, res);
	return res;
}		
    
};

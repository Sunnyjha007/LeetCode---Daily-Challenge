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
private:
TreeNode* solve(vector<int>& inorder,int ios,int ioe,vector<int>& postorder,int pos,int poe,unordered_map<int,int>& mp){
    if(ios>ioe||pos>poe)return NULL;
    TreeNode* root = new TreeNode(postorder[poe]);
    if(ios==ioe||pos==poe)return root;
    int index = mp[postorder[poe]];
    int offset = index - ios;
    int lins = ios;
    int line = index-1;
    int lpos = pos;
    int lpoe = lpos+offset-1;
    int rins = index+1;
    int rine = ioe;
    int rpos = lpoe+1;
    int rpoe = poe-1;
    root->left = solve(inorder,lins,line,postorder,lpos,lpoe,mp);
    root->right = solve(inorder,rins,rine,postorder,rpos,rpoe,mp);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};

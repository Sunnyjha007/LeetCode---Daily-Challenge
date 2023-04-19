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
void solve(TreeNode* root,char path,int len,int& maxi){
    if(!root)return;
    maxi = max(maxi,len);
    if(path=='l'){
        solve(root->left,path,1,maxi);
        solve(root->right,'r',len+1,maxi);
    }else{
        solve(root->left,'l',len+1,maxi);
        solve(root->right,path,1,maxi);
    }
}
public:
    int longestZigZag(TreeNode* root) {
        int maxi = 0;
        solve(root->left,'l',1,maxi);
        solve(root->right,'r',1,maxi);
        return maxi;

    }
};

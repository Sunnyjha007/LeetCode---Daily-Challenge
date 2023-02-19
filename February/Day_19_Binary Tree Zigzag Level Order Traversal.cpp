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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> pn;
        int i=0;
        pn.push(root);
        while(!pn.empty()){
            int size = pn.size();
            vector<int> v;
            while(size--){
                auto front = pn.front();pn.pop();
                v.push_back(front->val);
                if(front->left)pn.push(front->left);
                if(front->right)pn.push(front->right);
            }
            if(i%2==0){
                ans.push_back(v);
            }else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            i++;
        }
        return ans;
    }
};

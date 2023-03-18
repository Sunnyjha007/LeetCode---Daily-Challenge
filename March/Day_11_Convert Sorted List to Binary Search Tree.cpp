/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
pair<ListNode*,ListNode*> findMiddle(ListNode* head){
    if(!head||!head->next)return {nullptr,head};
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;
    while(fast&&fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return {prev,slow};
}
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return nullptr;
        //first -> prev, second -> mid
        pair<ListNode*,ListNode*> middle = findMiddle(head);
        ListNode* prev = middle.first;
        ListNode* mid = middle.second;
         TreeNode* root = new TreeNode(mid->val);
        if(prev){
             prev->next = nullptr;
             root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(mid->next);
        return root;
    }
};

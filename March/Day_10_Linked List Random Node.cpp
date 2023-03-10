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
class Solution {
    int length = 0;
    ListNode* headNode;
public:
    Solution(ListNode* head) {
        headNode = head;
        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int idx = rand()%length;
        ListNode* temp = headNode;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

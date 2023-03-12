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
public:
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        while(a&&b){
            if(a->val<=b->val){
                temp->next = new ListNode(a->val);
                a = a->next;
            }else{
                temp->next = new ListNode(b->val);
                b = b->next;
            }
            temp = temp->next;
        }
        if(a)temp->next = a;
        if(b)temp->next = b;
        return head->next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists,int si,int ei){
        if(si>ei)return NULL;
        if(si==ei)return lists[si];
        int mid = (si+ei)/2;
        ListNode* a = mergeSort(lists,si,mid);
        ListNode* b = mergeSort(lists,mid+1,ei);
        return merge(a,b);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeSort(lists,0,n-1);
    }
};

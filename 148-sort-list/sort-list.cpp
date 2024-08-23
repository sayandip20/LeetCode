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

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* List1, ListNode* List2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(List1 != NULL && List2 != NULL){
            if(List1->val < List2->val){
                temp->next = List1;
                temp = List1;
                List1 = List1->next;
            }
            else{
                temp->next = List2;
                temp = List2;
                List2 = List2->next;
            }
        }
        if(List1) temp->next = List1;
        else temp->next = List2;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
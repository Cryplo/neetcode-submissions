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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* first = new ListNode((l1->val + l2->val) % 10);
        ListNode* tracker = first;
        if(l1->val + l2->val >= 10) carry = true;
        l1 = l1->next;
        l2 = l2->next;
        while((l1 != nullptr || l2 != nullptr) || carry == true){
            int sum = carry ? 1 : 0;
            carry = false;
            if(l1 != nullptr) sum += l1->val;
            if(l2 != nullptr) sum += l2->val;
            ListNode* curr = new ListNode(sum % 10);
            tracker->next = curr;
            tracker = curr;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            if(sum >= 10) carry = true;
        }
        return first;
    }
};

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
    ListNode* reverse(ListNode* curr){
        if(curr->next == nullptr) return curr;
        ListNode* rev = reverse(curr->next);
        curr->next->next= curr;
        curr->next = nullptr;
        return rev;
    }

    void reorderList(ListNode* head) {
        if(head->next == nullptr) return head;
        //divide the list into 2 halves based on length
        //reverse the last half
        //afterwards merge the two
        int count = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        curr = head;
        for(int i = 0; i < count / 2; i++){
            curr = curr -> next;
        }
        cout << curr->val << endl;
        //curr is now the beginning of the second
        ListNode* two = reverse(curr);
        ListNode* stop = curr;
        ListNode* one = head;
        ListNode* carryOver = nullptr;
        cout << stop->val << endl;
        while(one != stop){
            if(carryOver != nullptr) carryOver->next = one;
            ListNode* a = one->next;
            ListNode* b = two->next;
            one->next = two;
            carryOver = two;
            one = a;
            two = b;
        }
        if(two != nullptr) carryOver->next = two;
    }
};

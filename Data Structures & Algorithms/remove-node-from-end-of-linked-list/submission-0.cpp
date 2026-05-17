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
    //first argument is the head of the list, second is what is "left"
    pair<ListNode*, int> recurs(ListNode* curr, int n){
        if(curr -> next == nullptr) {
            if(n == 0){
                return {nullptr, 0};
            }
            return {curr, n - 1};
        }
        pair<ListNode*, int> result = recurs(curr->next, n);
        if(result.second == -1) curr->next = curr->next->next;
        return {curr, result.second - 1};
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return recurs(head, --n).first;
    }
};

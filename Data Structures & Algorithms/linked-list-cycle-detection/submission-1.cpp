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
    //floyd algorithm
    bool hasCycle(ListNode* head) {
        ListNode* t = head;
        ListNode* h = head;
        while(h != nullptr && t != nullptr && h != t){
           h = h->next;
           if(h == nullptr) return false; 
           if(h == t) return true;
           h = h -> next;
           if(h == nullptr) return false;
           if(h == t) return true;
           t = t -> next;
           if(t == nullptr) return false;
           if(h == t) return true;

        }
        if(h == t && h != nullptr) return true;
        return false;
    }
};

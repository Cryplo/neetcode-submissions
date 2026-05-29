/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        vector<Node*> nodes;
        unordered_map<Node*, Node*> m;
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            nodes.push_back(newNode);
            m[curr] = newNode;
            curr = curr->next;
        }
        curr = head;
        for(int i = 0; i < nodes.size(); i++){
            if(i > 0) nodes[i - 1]->next = nodes[i];
            nodes[i]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * node = head; // pointer to traverse the list
        unordered_set<ListNode*>st; 
        if(!head || head->next==NULL) return NULL; 
        while(head){
            if(head==NULL) return NULL; // if the node is NULL return NULL
            if(st.count(head)) return head; // if the node is already in the set return the node
            st.insert(head); 
            head=head->next; 
        }
        return NULL;
    }
};

// Optimized Approach
class Solution {
public: 
    ListNode *detectCycle(ListNode *head) {
        if(!head || head->next==NULL) return NULL; 
        ListNode * slow = head; // slow pointer
        ListNode * fast = head; // fast pointer
        while(fast && fast->next){
            slow=slow->next; // move the slow pointer by one step
            fast=fast->next->next; // move the fast pointer by two steps
            if(slow==fast){ // if the slow and fast pointers meet, there is a cycle
                ListNode * node = head; 
                while(node!=slow){ 
                    node=node->next; 
                    slow=slow->next;
                }
                return node;
            }
        }
        return NULL; 
    }
};
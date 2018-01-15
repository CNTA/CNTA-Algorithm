/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    if (head == NULL)
        return false;
    
    // Floyd's cycle-finding algorithm:
    // - Move two nodes at different speeds within a infinity loop. 
    // - If the list has a cycle (or more), they would meet at some time.
    // - Otherwise one of them would reach end of the list.
    Node* slow = head;
    Node* fast = head;
    while (true)
    {
        slow = slow->next;
        if (fast->next == NULL)
            return false;
        fast = fast->next->next;
        
        if (slow == NULL || fast == NULL)
            return false;
        
        if (slow == fast)
            return true;
    }
}

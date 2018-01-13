/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* temp = NULL;
    Node* t = head;
    while (t != NULL)
    {
        temp = t->prev;
        t->prev = t->next;
        t->next = temp;
        
        t = t->prev;
    }
    
    head = temp->prev;
    return head;
}



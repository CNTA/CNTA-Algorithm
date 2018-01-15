/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;
    
    Node* t = head;
    while (t != NULL)
    {
        while (t->next != NULL && t->data == t->next->data)
        {
            Node* duplicated = t->next;
            t->next = t->next->next;
            delete duplicated;
        }
        
        t = t->next;
    }
    
    return head;
}


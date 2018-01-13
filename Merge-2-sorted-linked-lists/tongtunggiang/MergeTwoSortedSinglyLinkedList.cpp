/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL && headB == NULL)
        return NULL;
    
    if (headA == NULL)
    {
        return headB;
    }
    else if (headB == NULL)
    {
        return headA;
    }
    
    Node* head = new Node();    
    Node* next = new Node();
    if (headA->data < headB->data)
    {
        head->data = headA->data;
        next = MergeLists(headA->next, headB);
        head->next = next;
    }
    else
    {
        head->data = headB->data;
        next = MergeLists(headA, headB->next);
        head->next = next;
    }
    
    return head;
}


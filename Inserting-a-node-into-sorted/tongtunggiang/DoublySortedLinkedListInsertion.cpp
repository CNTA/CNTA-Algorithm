/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head, int data)
{    
    Node* newNode = new Node();
    newNode->data = data;
    
    if (head == NULL) // Empty list
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
    
    if (head->data > data)
    {
        newNode->prev = NULL;
        newNode->next = head;
        return newNode;
    }
    
    Node* traverse = head;
    while (traverse->next != NULL)
    {
        traverse = traverse->next;
        
        if (traverse->data > data)
        {
            newNode->prev = traverse->prev;
            traverse->prev->next = newNode;
            
            newNode->next = traverse;            
            traverse->prev = newNode;
            
            return head;
        }
    }
    
    // traverse is the last fucking node
    newNode->prev = traverse;
    traverse->next = newNode;
    
    newNode->next = NULL;
    return head;
}


// I have to use the fucking nano text editor in git bash because I have no damn idea about why this folder cannot be accessed via Windows Explorer.

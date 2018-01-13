/*
    Remove all duplicate elements from a sorted Linked List
    Node is defined as
    var Node = function(data) {
        this.data = data;
        this.next = null;
    }
*/

// This is a "method-only" submission.
// You only need to complete this method.

function removeDuplicates(head) {
    if(head == null) {
        return head;
    }
    var nextNode = head.next;
    while(nextNode != null) {
        if(nextNode.data != head.data) {
            break;
        }
        nextNode = nextNode.next;
    }
    head.next = removeDuplicates(nextNode);
    return head;
}

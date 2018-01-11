/*
    Reverse a doubly linked list, input list may also be empty
    Node is defined as
    var Node = function(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
*/

// This is a "method-only" submission.
// You only need to complete this method.

function reverse(head) {
    if (head == null) {
        return head;
    }
    var next = head.next
    head.next = head.prev
    head.prev = reverse(next)
    return head.prev != null ? head.prev : head;
}

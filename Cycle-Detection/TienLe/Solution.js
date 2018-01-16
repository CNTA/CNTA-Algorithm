/*
    Detect a cycle in a Linked List.
    Note that the head may be 'null' if the list is empty.
    Node is defined as
    var Node = function(data) {
        this.data = data;
        this.next = null;
    }
*/

// This is a "method-only" submission.
// You only need to complete this method.

function hasCycle(head) {
    if (head == null || head.next == null) {
        return false
    }
    var pointerOne = head
    var pointerTwo = head.next.next
    while(pointerOne != pointerTwo) {
        if (pointerOne == null || pointerTwo == null || pointerTwo.next == null) {
            return false
        }
       pointerOne = pointerOne.next
       pointerTwo = pointerTwo.next.next
    }
    return true
}

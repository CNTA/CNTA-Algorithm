/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
    Node is defined as
    var Node = function(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
*/

// This is a "method-only" submission.
// You only need to complete this method.

function sortedInsert(head, data) {
    if (head == null) { // Empty lists
        var first = new Node()
        first.data = data        
        return first
    } else if(head.data > data) { // data < number in 1st node
        var first = new Node()
        first.data = data
        first.next = head
        head.prev = first
        return first
    }
    var nextNode = head
    while(nextNode.next != null){ // number in 1st node < data < nubmer in last node
        nextNode = nextNode.next
        if (nextNode.data >= data){
            var newNode = new Node()
            newNode.data = data;
            var prev = nextNode.prev;
            prev.next = newNode
            nextNode.prev = newNode;
            newNode.next = nextNode
            newNode.prev = prev
            return head
        }
    }
    // data is the highest number in lists
    var newNode = new Node()
    newNode.data = data;
    newNode.prev = nextNode;
    nextNode.next = newNode;
    return head
}
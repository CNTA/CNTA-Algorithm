class Node {
  constructor(value) {
    this.left = null;
    this.right = null;
    this.value = value;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  insert(value) {
    const newNode = new Node(value);

    if (!this.root) {
      this.root = newNode;
    } else {
      let currentNode = this.root;

      while (true) {
        if (value < currentNode.value) {
          // Go LEFT
          if (!currentNode.left) {
            currentNode.left = newNode;
            return this;
          }

          currentNode = currentNode.left;
        } else {
          // Go RIGHT
          if (!currentNode.right) {
            currentNode.right = newNode;
            return this;
          }
          currentNode = currentNode.right;
        }
      }
    }
  }

  lookup(value) {
    if (!this.root) {
      return false;
    }

    let currentNode = this.root;

    while (currentNode) {
      if (value < currentNode.value) {
        currentNode = currentNode.left;
      } else if (value > currentNode.value) {
        currentNode = currentNode.right;
      } else if (currentNode.value === value) {
        return currentNode;
      }
    }

    return false;
  }

  remove(value) {
    if (!this.root) {
      return false;
    }

    let currentNode = this.root;
    let parentNode = null;

    while (currentNode) {
      if (value < currentNode.value) {
        parentNode = currentNode;
        currentNode = currentNode.left;
      } else if (value > currentNode.value) {
        parentNode = currentNode;
        currentNode = currentNode.right;
      } else if (currentNode.value === value) {
        // Option 1: No RIGHT CHILD
        if (currentNode.right === null) {
          if (parentNode === null) {
            this.root = currentNode.left;
          } else {
            // if parent > current, make current left child to be the left child of the parent
            if (currentNode.value < parentNode.value) {
              parentNode.left = currentNode.left;
            } else {
              // if parent < current, make left child of current node to be the right child of parent
              parentNode.right = currentNode.left;
            }
          }
        } else if (currentNode.right.left === null) {
          // Option2: RIGHT child doesn't have any left child
          if (parentNode === null) {
            this.root = currentNode.left;
          } else {
            // if parent > current, make right child of current to be the left child of the parent

            if (parentNode.value > currentNode.value) {
              parentNode.left = currentNode.right;
            } else {
              // if parent < current, make right child of current to be the right child of the parent
              parentNode.right = currentNode.right;
            }
          }
        } else {
          // Option 3: RIGHT child have a left child

          // find the Right child's left most child
          let leftmost = currentNode.right.left;
          let leftmostParent = currentNode.right;
          while (leftmost.left !== null) {
            leftmostParent = leftmost;
            leftmost = leftmost.left;
          }

          // Parent's left subtree is now leftmost's right subtree
          leftmostParent.left = leftmost.right;
          leftmost.left = currentNode.left;
          leftmost.right = currentNode.right;

          if (parentNode === null) {
            this.root = leftmost;
          } else {
            if (currentNode.value < parentNode.value) {
              parentNode.left = leftmost;
            } else if (currentNode.value > parentNode.value) {
              parentNode.right = leftmost;
            }
          }
        }
        return true;
      }
    }
  }

  breadFirstSearch() {
    let currentNode = this.root;
    const list = [];
    const queue = [];
    queue.push(currentNode);

    while (queue.length > 0) {
      currentNode = queue.shift();
      list.push(currentNode.value);
      if (currentNode.left) {
        queue.push(currentNode.left);
      }
      if (currentNode.right) {
        queue.push(currentNode.right);
      }
    }
    return list;
  }

  breadFirstSearchRecursive(queue, list) {
    if (!queue.length) {
      return list;
    }

    const currentNode = queue.shift();
    list.push(currentNode.value);
    if (currentNode.left) {
      queue.push(currentNode.left);
    }
    if (currentNode.right) {
      queue.push(currentNode.right);
    }

    return this.breadFirstSearchRecursive(queue, list);
  }

  DFSInOrder() {
    return traverseInOrder(this.root, []);
  }

  DFSPostOrder() {
    return traversePostOrder(this.root, []);
  }

  DFSPreOrder() {
    return traversePreOrder(this.root, []);
  }
}

function traverseInOrder(node, list) {
  if (node.left) {
    traverseInOrder(node.left, list);
  }

  list.push(node.value);
  if (node.right) {
    traverseInOrder(node.right, list);
  }

  return list;
}

function traversePreOrder(node, list) {
  list.push(node.value);
  if (node.left) {
    traversePreOrder(node.left, list);
  }

  if (node.right) {
    traversePreOrder(node.right, list);
  }

  return list;
}

function traversePostOrder(node, list) {
  if (node.left) {
    traversePostOrder(node.left, list);
  }

  if (node.right) {
    traversePostOrder(node.right, list);
  }

  list.push(node.value);

  return list;
}

const myTree = new BinarySearchTree();

myTree.insert(9);
myTree.insert(4);
myTree.insert(6);
myTree.insert(20);
myTree.insert(170);
myTree.insert(15);
myTree.insert(1);

function traverse(node) {
  const tree = { value: node.value };
  tree.left = node.left === null ? null : traverse(node.left);
  tree.right = node.right === null ? null : traverse(node.right);
  return tree;
}

console.log(JSON.stringify(traverse(myTree.root)));
console.log('\n\n\n');
console.log(myTree.lookup(20));
console.log('\n\n\n');

myTree.remove(6);

console.log(JSON.stringify(traverse(myTree.root)));
console.log('\n\n\n');

myTree.insert(6);

console.log(myTree.breadFirstSearch());
console.log(myTree.breadFirstSearchRecursive([myTree.root], []));

console.log('\n\n\n');

console.log(myTree.DFSInOrder());
console.log(myTree.DFSPreOrder());
console.log(myTree.DFSPostOrder());

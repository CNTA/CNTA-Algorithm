//: Playground - noun: a place where people can play

import Foundation
struct Node {
    let x: Int
    let y: Int
}

extension Node {
    static func ==(lhs: Node, rhs: Node) -> Bool {
        return lhs.x == rhs.x && lhs.y == rhs.y
    }
}
let N = Int(readLine()!)!
//
let xDENOTES = "X"
let edgeSymbol = "."
// Read all inputs
var inputs: [[String]] = []
var flags = Array(repeatElement(Array(repeatElement(false, count: N)), count: N))
for _ in 0..<N {
    let line = readLine()!
    inputs.append(line.map{String($0)})
}

let line = readLine()!
let numbers = line.components(separatedBy: " ").flatMap({Int($0)})
let startNode = Node(x: numbers[0], y: numbers[1])
let endNode = Node(x: numbers[2], y: numbers[3])

// Using BFS to find the shortest path
var isFound = false
var queue: [Node] = []
var numberOfStep = 0
queue.append(startNode)
while(!isFound) {
    var appendingToQueue: [Node] = []
    while(!queue.isEmpty) {
        let node = queue.removeFirst()
        if node == endNode {
            isFound = true
            break
        }
        if flags[node.x][node.y] {
            continue
        }
        flags[node.x][node.y] = true
        for i in node.x+1..<N {
            if inputs[i][node.y] == xDENOTES {
                break
            }
            appendingToQueue.append(Node(x: i, y: node.y))
        }
        for i in stride(from: node.x-1, to: -1, by: -1) {
            if inputs[i][node.y] == xDENOTES {
                break
            }
            appendingToQueue.append(Node(x: i, y: node.y))
        }
        for i in node.y+1..<N {
            if inputs[node.x][i] == xDENOTES {
                break
            }
            appendingToQueue.append(Node(x: node.x, y: i))
        }
        for i in stride(from: node.y-1, to: -1, by: -1) {
            if inputs[node.x][i] == xDENOTES {
                break
            }
            appendingToQueue.append(Node(x: node.x, y: i))
        }
    }
    if isFound {
        break
    }
    numberOfStep += 1
    queue.append(contentsOf: appendingToQueue)
    if queue.isEmpty {
        break
    }
}
print(numberOfStep)










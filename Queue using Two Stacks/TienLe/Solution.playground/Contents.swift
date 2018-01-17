//: Playground - noun: a place where people can play

import Foundation

let numberOfAction = Int(readLine()!)!
var queues: [Int] = []
for _ in 0..<numberOfAction {
    let line = readLine()!
    let numbers = line.components(separatedBy:" ").flatMap({Int($0)})
    let operationNumber = numbers[0]
    if (operationNumber == 1) {
        let number = numbers[1]
        queues.append(number)
    } else if (operationNumber == 2) {
        queues.removeFirst()
    } else if (operationNumber == 3) {
        print(queues.first!)
    }
}



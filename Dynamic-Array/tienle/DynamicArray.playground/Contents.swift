//: Playground - noun: a place where people can play

import Foundation

var line = readLine()!
var numbers = line.components(separatedBy:" ").flatMap({Int($0)})
let N = numbers[0]
let Q = numbers[1]

var lastAnswer = 0
var seqs: [[Int]] = [[Int]](repeatElement([], count: N))
for _ in 0..<Q {
    line = readLine()!
    numbers = line.components(separatedBy:" ").flatMap({Int($0)})
    let typeQuery = numbers[0]
    let x = numbers[1]
    let y = numbers[2]
    let index = (x ^ lastAnswer) % N
    if typeQuery == 1 {
        seqs[index].append(y)
    } else {
        let size = seqs[index].count
        lastAnswer = (seqs[index])[y%size]
        print(lastAnswer)
    }
}

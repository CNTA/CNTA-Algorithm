//: Playground - noun: a place where people can play

import Foundation

var numbers: [Int] = []
var leftRotationNumber = 0
// Uncomment to submit code to Hackerank
/*
var line = readLine()!
let strings = line.components(separatedBy:" ")
let nubmerOfElement = Int(strings[0])!
let leftRotationNumber = Int(strings[1])!
line = readLine()!
numbers = line.components(separatedBy:" ").flatMap({Int($0)})
 */
var result: [Int] = []
result.append(contentsOf: numbers[leftRotationNumber..<(numbers.count)])
result.append(contentsOf: numbers[0..<leftRotationNumber])

var output: String = ""
for number in result {
    output += "\(number) "
}
print(output)


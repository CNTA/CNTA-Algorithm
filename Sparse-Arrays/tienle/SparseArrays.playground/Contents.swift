//: Playground - noun: a place where people can play
// Sparse Arrays
import Foundation

var strings: [String] = []
var queries :[String] = []
// Uncomment if you want to submit your code in hackerank
/*
var line = readLine()!
var numberOfLine = Int(line)!
for _ in 1...numberOfLine {
    line = readLine()!
    strings.append(line)
}
line = readLine()!
numberOfLine = Int(line)!
for _ in 1...numberOfLine {
    line = readLine()!
    queries.append(line)
}
*/
for query in queries {
    var count = 0
    for string in strings {
        if string == query {
            count += 1
        }
    }
    print(count)
}



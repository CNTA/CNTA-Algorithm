// Arrray Manipulation

import Foundation

var line = readLine()!
var strings = line.components(separatedBy:" ")
let numberOfElement = Int(strings[0])!
let numberOfUpdate = Int(strings[1])!
var numbers = [Int](repeatElement(0, count: numberOfElement))

for _ in 0..<numberOfUpdate {
    line = readLine()!
    strings = line.components(separatedBy:" ")
    let startIndex = Int(strings[0])!
    let endIndex = Int(strings[1])!
    let increasedValue = Int(strings[2])!
    numbers[startIndex - 1] += increasedValue
    if (endIndex < numberOfElement) {
        numbers[endIndex] -= increasedValue
    }
}
var maxNumber = Int.min
var result = 0
for number in numbers {
    result = result + number
    maxNumber = maxNumber > result ? maxNumber : result
}
print(maxNumber)

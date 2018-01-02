//: Playground - noun: a place where people can play
// 2D Array - DS
import Foundation

var inputArrays:[Int] = [1, 1, 1, 0, 0, 0,
                         0, 1, 0, 0, 0, 0,
                         1, 1, 1, 0, 0, 0,
                         0, 0, 2, 4, 4, 0,
                         0, 0, 0, 2, 0, 0,
                         0, 0, 1, 2, 4, 0]

// Generate 2d array
// Uncomment if you want to submit your code to Hackerank
/*
var stringInput = ""
while let line = readLine() {
    stringInput += line + " "
}
let strings = stringInput.components(separatedBy:" ")
inputArrays  = strings.flatMap({Int($0)})
*/
var maximumNumber = Int.min
for i in 0...3 {
    for j in 0...3 {
        let hourglassNumber = inputArrays[i*6 + j] + inputArrays[i*6 + j + 1] + inputArrays[i*6 + j + 2] + inputArrays[(i + 1) * 6 + j + 1] + inputArrays[(i + 2) * 6 + j] + inputArrays[(i + 2) * 6 + j + 1] + inputArrays[(i + 2) * 6 + j + 2]
        maximumNumber = hourglassNumber > maximumNumber ? hourglassNumber : maximumNumber
    }
}
print(maximumNumber)

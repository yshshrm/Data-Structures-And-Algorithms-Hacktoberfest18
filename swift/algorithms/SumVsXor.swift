import Foundation

func solve(n: Int) -> Int {
    var c:Int=0, k:Int=n;
    while k != 0{
        c+=k%2==1 ? 0:1
        k/=2
    }
    return NSDecimalNumber(decimal: pow(2, c)).intValue
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard var n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

let result = solve(n: n)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

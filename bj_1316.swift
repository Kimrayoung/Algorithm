import Foundation

func check(_ s: String) -> Bool {
	var dic: [Character : Bool] = [:]
    var prev: Character? = nil
	for c in s {
		if dic[c] == nil {
            dic[c] = true
        } else {
            if let prev = prev {
                if prev != c { return false }
            }
        }
		prev = c
	}
    return true
}

func main() {
    let n = Int(readLine()!)!
	var ret: Int = 0

	for _ in 0..<n {
		let s = readLine()!
		ret += check(s) ? 1 : 0
	}
    print(ret)
}
main()
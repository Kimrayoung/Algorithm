import Foundation

func main() {
	let s = readLine()!
    var temp: String = ""
    var ret: [String] = []
    var isGalho = false
    for c in s {
        temp += String(c)
        if c == "<" { isGalho = true }
        if c == ">" {
            ret.append(temp)
            temp = ""
            isGalho = false
        } else if c == "<" && temp != "<" {
            temp.removeLast()
            ret.append(String(temp.reversed()))
            temp = "<"
        }
        else if c == " " && !isGalho {
            temp.removeLast()
            ret.append(String(temp.reversed()) + " ")
            temp = ""
        }
    }
    if temp != "" { ret.append(String(temp.reversed())) }
    print(ret.joined())
    
}

main()
import Foundation

var visited: [[Int]] = Array(repeating: Array(repeating: 0, count: 204), count: 204);
var ret: Int = 0
var cnt: Int = 0

func dfs(_ index: Int, _ second: Int, _ computers: [[Int]], _ n: Int) {
    for i in 0..<n {
        if visited[index][i] == 1 || computers[index][i] == 0 { continue }
        visited[index][i] = 1
        dfs(i, 0, computers, n)
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    for i in 0..<n {
        for j in 0..<n {
            if visited[i][j] == 1 || computers[i][j] == 0 { continue }
            visited[i][j] = 1
            dfs(i, j, computers, n)
            ret += 1
        }
    }
    return ret
}
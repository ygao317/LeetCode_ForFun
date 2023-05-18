object Solution {
    def findSmallestSetOfVertices(n: Int, edges: List[List[Int]]): List[Int] = {
        val a = Array.fill[Boolean](n)(true)
        for (e <- edges) a(e.tail.head) = false
        (0 until n).filter(a(_)).toList
    }
}

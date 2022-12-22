object Solution {
    def sumOfDistancesInTree(n: Int, edges: Array[Array[Int]]): Array[Int] = {
        val g = collection.mutable.HashMap.empty[Int, List[Int]]
        for (e <- edges){
            g(e(0)) = e(1) :: g.getOrElse(e(0), Nil)
            g(e(1)) = e(0) :: g.getOrElse(e(1), Nil)
        }
        
        val count = Array.fill[Int](n)(1)
        val ans = Array.fill[Int](n)(0)
        
        def dfs(node: Int = 0, parent: Int = -1): Unit = for (child <- g.getOrElse(node, Nil) if child != parent) {
            dfs(child, node)
            count(node) += count(child)
            ans(node) += ans(child) + count(child)
        }
        
        def dfs2(node: Int = 0, parent: Int = -1): Unit = for (child <- g.getOrElse(node, Nil) if child != parent) {
            ans(child) = ans(node) - count(child) + n - count(child)
            dfs2(child, node)
        }
        
        dfs(); dfs2(); ans
    }
}

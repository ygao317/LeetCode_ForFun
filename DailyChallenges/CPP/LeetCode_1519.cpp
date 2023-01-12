object Solution {
    def countSubTrees(n: Int, edges: Array[Array[Int]], labels: String): Array[Int] = {
        val m = scala.collection.mutable.Map.empty[Int, List[Int]]
        for (e <- edges){
            m(e(0)) = e(1) :: m.getOrElse(e(0), Nil)
            m(e(1)) = e(0) :: m.getOrElse(e(1), Nil)
        }

        val ans = Array.ofDim[Int](n)
        def dfs(node: Int): Array[Int] = {
            ans(node) = 1
            val cnt = Array.ofDim[Int](26)
            cnt(labels(node) - 'a') = 1
            for (ch <- m(node) if ans(ch) == 0){
                val ch_cnt = dfs(ch)
                for (i<- 0 until 26) cnt(i) += ch_cnt(i) 
            }
            ans(node) = cnt(labels(node) - 'a')
            cnt
        }

        dfs(0)
        ans;
    }
}

object Solution {
    def longestCycle(edges: Array[Int]): Int = {
        val m = Array.fill[(Int, Int)](edges.length)((-1, -1)) //dist, from
        var res = -1

        def dfs(f: Int, j: Int, d: Int): Unit = if (j != -1){
            if (m(j)._1 == -1) {
                m(j) = (d, f) // update if not reach before
                dfs(f, edges(j), d+1)
            }else{
                if (m(j)._2 == f) 
                    res = Math.max(res, d - m(j)._1)    
            }
        }

        for (i <- 0 until edges.length) dfs(i, i, 0)
        
        res
    }
}

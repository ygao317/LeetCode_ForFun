object Solution {
    def largestPathValue(colors: String, edges: Array[Array[Int]]): Int = {
        // Initialize the graph
        val n = colors.length
        val graph = collection.mutable.HashMap.empty[Int, List[Int]]
        val ins = Array.fill[Int](n)(0) // record how many dependency nodes
        for (e <- edges) {
            graph(e(0)) = e(1) :: graph.getOrElse(e(0), Nil)
            ins(e(1)) += 1
        }
        
        val cc = Array.fill[Int](n,26)(0) // max count of each color from dependencies to this node
        
        // Initialize the colour count at the beginning node where no dependencies
        val q = collection.mutable.Queue.empty[Int] // standard way to do topo sort
        for (i <- 0 until n if ins(i) == 0){
            q.enqueue(i)
            cc(i)(colors(i) - 'a') += 1
        }
        
        var cnt = 0
        var ans = 0
        while (q.nonEmpty) {
            val u = q.dequeue
            ans = ans max cc(u).max
            cnt += 1    // If a cycle existing, nodes in that cycle will never become a start node. So here need to do BFS.
            for (v <- graph.getOrElse(u, Nil)) {
                for (i <- 0 to 25; p = (i == colors(v) - 'a')) 
                     cc(v)(i) = cc(v)(i) max (cc(u)(i) + (if (p) 1 else 0))
                ins(v) -= 1
                if (ins(v) == 0) q.enqueue(v)
            }
        }
    
        if (cnt < n) -1 else ans 
    }
}

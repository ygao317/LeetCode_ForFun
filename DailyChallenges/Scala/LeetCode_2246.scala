object Solution {
    def longestPath(parent: Array[Int], s: String): Int = {
        // Standard process to prepare a map of children
        val m = scala.collection.mutable.Map.empty[Int, List[Int]]
        for (i <- 1 until parent.length)
            m(parent(i)) = i :: m.getOrElse(parent(i), Nil)
        
        // When two adjacent nodes share same label, it break the edge actually.
        // can be treated as a seperate tree root at child node.
        val q = scala.collection.mutable.Queue.empty[Int]
        q.enqueue(0)
        
        var ans = 1;
        def dfs(node: Int): Int = {
            if (!m.contains(node)) return 1 // leaf
            val big2 = Array(0, 0, 0)
            for (ch <- m(node)){
                if (s(node) == s(ch)) q.enqueue(ch) else {
                    val cl = dfs(ch)
                    if (cl > big2(1)) big2(1) = cl
                    if (big2(1) > big2(0)){ // swap 1st and 2nd using 3rd as a tmp
                        big2(2) = big2(1); big2(1) = big2(0); big2(0) = big2(2)
                    }
                }
            }
            ans = Math.max(ans, big2(0)+big2(1)+1)
            big2(0)+1
        }

        while (q.nonEmpty) dfs(q.dequeue)
        
        ans
    }
}

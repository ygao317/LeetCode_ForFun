object Solution {
    def shortestAlternatingPaths(n: Int, redEdges: Array[Array[Int]], blueEdges: Array[Array[Int]]): Array[Int] = {
        val m = collection.mutable.HashMap.empty[Int, List[Int]]
        for (a <- redEdges) m(a(0)) = (n+a(1)) :: m.getOrElse(a(0), Nil)
        for (a <- blueEdges) m(n+a(0)) = a(1) :: m.getOrElse(n+a(0), Nil)
        
        val ans = Array.fill[Int](2*n)(-1); ans(0) = 0; ans(n) = 0
        val q = collection.mutable.Queue.empty[Int]; q.enqueue(0); q.enqueue(n)
        while (q.nonEmpty){
            for (i <- 0 until q.length; src = q.dequeue if m contains src; des <- m(src) if ans(des) == -1){
                ans(des) =  ans(src)+1
                q.enqueue(des)
            }
        }

        for (i<- 1 until n; if (ans(i) == -1 || (ans(n+i) != -1 && ans(n+i) < ans(i))))
            ans(i) = ans(n+i)

        ans.take(n)
    }
}

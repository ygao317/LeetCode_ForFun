object Solution {
    def findCheapestPrice(n: Int, flights: Array[Array[Int]], src: Int, dst: Int, k: Int): Int = {
        val m = Array.fill[List[(Int, Int)]](n){Nil}
        for (a <- flights)
            m(a(0)) = (a(1), a(2)) :: m(a(0))
        
        val dsts = Array.fill[Int](n){Int.MaxValue}; dsts(src) = 0
        val q = scala.collection.mutable.Queue.empty[(Int, Int)]; q.enqueue((src, 0))
        
        var cnt = 0
        while (cnt <= k && q.nonEmpty){
            cnt += 1
            for (i <- 0 until q.length; (st, st_cost) = q.dequeue; (ed, cost) <- m(st) if cost+st_cost < dsts(ed)){
                dsts(ed) = cost + st_cost
                q.enqueue((ed, dsts(ed)))
            }
        }
        
        if (dsts(dst) == Int.MaxValue) -1 else dsts(dst)
    }
}

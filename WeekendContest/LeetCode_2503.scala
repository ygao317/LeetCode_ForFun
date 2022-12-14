object Solution {
    def maxPoints(grid: Array[Array[Int]], queries: Array[Int]): Array[Int] = {
        val qs = queries.zipWithIndex.sorted
        
        val m = grid.length; val n = grid(0).length; val dir = Array(1,0,-1,0,1)
        val pq = scala.collection.mutable.PriorityQueue.empty[(Int, Int, Int)](Ordering.by((_: (Int, Int, Int))._1).reverse); pq.enqueue((grid(0)(0), 0, 0)); grid(0)(0) = -1

        val ans = new Array[Int](queries.length); var count = 0
        for ((q, idx) <- qs){
            while (!pq.isEmpty && pq.head._1 < q){
                val (_, x0, y0) = pq.dequeue
                for (d <- 0 to 3; x = x0 + dir(d) if (x >= 0 && x < m); 
                     y = y0 + dir(d+1) if (y >= 0 && y < n); if grid(x)(y) != -1){
                    pq.enqueue((grid(x)(y), x, y))
                    grid(x)(y) = -1 // visited     
                }
                count += 1
            }
            ans(idx) = count
        }
        ans
    }
}

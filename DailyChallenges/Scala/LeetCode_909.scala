object Solution {
    def snakesAndLadders(board: Array[Array[Int]]): Int = {
        val n = board.length
        var ans = 0
        val visited = Array.ofDim[Boolean](n*n+1); visited(1) = true
        val q = scala.collection.mutable.Queue.empty[Int]; q.enqueue(1)
        while (q.nonEmpty){
            ans += 1
            val sz = q.length
            for (i <- 0 until sz){
                val st = q.dequeue
                for (ed <- (st+1) to Math.min(st+6, n*n) if !visited(ed);
                    r1 = (ed-1)/n; c1 = (ed-1) % n; r = n-1-r1; c = if (r1%2 == 1) n-1-c1 else c1){
                    if (board(r)(c) != -1) q.enqueue(board(r)(c)) else q.enqueue(ed)
                    if (q.last == n*n) return ans
                    visited(ed) = true
                }
            }
        }
        -1
    }
}

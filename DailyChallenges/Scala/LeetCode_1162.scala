object Solution {
    def maxDistance(grid: Array[Array[Int]]): Int = {
        val n = grid.length
        val q = collection.mutable.Queue.empty[Int]
        for (i <- 0 until n; j <- 0 until n; if grid(i)(j) == 1)
            q.enqueue(i*100+j);
        
        val dir = Array(1, 0, -1, 0, 1)
        var steps = 0
        while (q.nonEmpty){
            steps += 1
            for (k <- 0 until q.length; num = q.dequeue; i = num/100; j = num%100;
                l <- 0 until 4; _i = i + dir(l) if _i>=0 && _i<n;
                _j = j + dir(l+1) if _j>=0 && _j<n; if grid(_i)(_j)==0){
                    grid(_i)(_j) = steps
                    q.enqueue(_i * 100 + _j)       
            }
        }
        if (steps <= 1) -1 else (steps-1)
    }
}

object Solution {
    def numEnclaves(grid: Array[Array[Int]]): Int = {
        val m = grid.length; val n = grid(0).length
        def fill(i: Int, j: Int): Int = if (i<0 || j<0 || i>=m || j>=n || grid(i)(j) == 0) 0 else{
            grid(i)(j) = 0
            1 + fill(i+1, j) + fill(i-1,j) + fill(i, j+1) + fill(i, j-1)
        }

        for (i <- List(0, m-1); j <- 0 until n) fill(i,j)
        for (j <- List(0, n-1); i <- 0 until m) fill(i,j)

        var ans = 0
        for (i <- 0 until m; j <- 0 until n)
            ans += fill(i,j)
        ans
    }
}

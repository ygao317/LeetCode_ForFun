object Solution {
    def minFallingPathSum(matrix: Array[Array[Int]]): Int = {
        val m = matrix.length; val n = matrix(0).length
        for (i <- 1 until m; j <- 0 until n)
            matrix(i)(j) += math.min(math.min(if (j==0) Int.MaxValue else matrix(i-1)(j-1), matrix(i-1)(j)), if (j == n-1) Int.MaxValue else matrix(i-1)(j+1))
        matrix(m-1).min
    }
}

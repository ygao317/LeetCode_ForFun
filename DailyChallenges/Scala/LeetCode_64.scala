object Solution {
    def minPathSum(grid: Array[Array[Int]]): Int = {
        for (i <- 0 until grid.length; j <- 0 until grid(0).length){
            (i, j) match {
                case (0, 0) => None
                case (0, _) => grid(i)(j) += grid(i)(j-1)
                case (_, 0) => grid(i)(j) += grid(i-1)(j)
                case _ => grid(i)(j) += Math.min(grid(i-1)(j), grid(i)(j-1))
            }
        }
        grid.last.last
    }
}

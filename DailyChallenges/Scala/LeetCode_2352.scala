object Solution {
    def equalPairs(grid: Array[Array[Int]]): Int = {
        grid.transpose.foldLeft(0)((c,r) => c + grid.count(_ sameElements r))
    }
}

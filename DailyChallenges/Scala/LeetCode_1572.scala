object Solution {
    def diagonalSum(mat: Array[Array[Int]]): Int = {
        val n = mat.length
        val p = mat.foldLeft((0, 0)){(p, a) => (p._1 + a(p._2) + a(n-1-p._2), p._2+1)}
        if (n%2 == 1) p._1 - mat(n/2)(n/2) else p._1
    }
}

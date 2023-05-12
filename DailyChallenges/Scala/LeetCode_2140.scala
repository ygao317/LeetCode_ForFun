object Solution {
    def mostPoints(questions: Array[Array[Int]]): Long = {
        val n = questions.length
        val dp = Array.fill[Long](n+1)(0)
        for (i <- (n-1) to 0 by -1)
            dp(i) = dp(i+1) max (questions(i)(0) + dp(n min (i+1+questions(i)(1))))
        dp(0)
    }
}

object Solution {
    def maxSatisfaction(satisfaction: Array[Int]): Int = {
        val ss = satisfaction.sorted
        val dp = Array.fill[Int](ss.length+1)(Int.MinValue); dp(0) = 0
        for (i <- 1 to ss.length; j <- i until 0 by -1)
            dp(j) = dp(j) max (dp(j-1) + j * ss(i-1))
        dp.max
    }
}

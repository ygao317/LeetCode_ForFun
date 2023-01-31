object Solution {
    def bestTeamScore(scores: Array[Int], ages: Array[Int]): Int = {
        val n = scores.length
        val players = ages.zip(scores).sorted
        val dp = Array.fill[Int](n)(0)
        var ans = 0
        for (i <- 0 until n){
            dp(i) = players(i)._2
            for (j <- 0 until i; if players(j)._2 <= players(i)._2)
                dp(i) = Math.max(dp(i), dp(j) + players(i)._2)
            ans = Math.max(ans, dp(i))
        }
        ans
    }
}

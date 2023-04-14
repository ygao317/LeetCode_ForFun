object Solution {
    def longestPalindromeSubseq(s: String): Int = {
        val n = s.length
        val dp = Array.fill[Int](n)(0)
        val dpPrev = Array.fill[Int](n)(0)

        for (i <- n-1 to 0 by -1){
            dp(i) = 1
            for (j <- i+1 until n){
                if (s(i) == s(j))
                    dp(j) = dpPrev(j-1) + 2
                else
                    dp(j) = dpPrev(j) max dp(j-1)
            }
            dp.copyToArray(dpPrev)
        }

        dp(n-1)
    }
}

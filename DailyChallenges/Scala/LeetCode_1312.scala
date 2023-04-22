object Solution {
    def minInsertions(s: String): Int = {
        val n = s.length
        val dp = Array.ofDim[Int](n+1, n+1)
        for (i <- 0 until n; j <- 0 until n)
            dp(i+1)(j+1) =  if (s(i) == s(n-1-j)) (dp(i)(j) + 1) else (dp(i)(j+1) max dp(i+1)(j))
        n- dp(n)(n)
    }
}

object Solution {
    def isScramble(s1: String, s2: String): Boolean = {
        val n = s1.length
        val dp = Array.ofDim[Boolean](n+1, n, n) // n+1 * n * n
        for (i <- 0 until n; j <- 0 until n) dp(1)(i)(j) = s1(i) == s2(j) // dp(1)
        for (len <- 2 to n; i <- 0 to n-len; j <- 0 to n-len; slen <- 1 until len){ // bottom up
            dp(len)(i)(j) |=  dp(slen)(i)(j) && dp(len-slen)(i+slen)(j+slen)
            dp(len)(i)(j) |=  dp(slen)(i)(j+len-slen) && dp(len-slen)(i+slen)(j)
        }
        dp(n)(0)(0)
    }
}

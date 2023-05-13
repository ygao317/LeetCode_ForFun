object Solution {
    def countGoodStrings(low: Int, high: Int, zero: Int, one: Int): Int = {
        val dp = Array.fill[Int](high+1)(0); dp(zero) += 1; dp(one) += 1
        val mod = 1000000007
        var ans = 0
        for (i <- 0 to high){
            if (i-zero>0) dp(i) = (dp(i) + dp(i-zero)) % mod
            if (i-one>0) dp(i) = (dp(i) + dp(i-one)) % mod
            if (i>=low) ans = (ans + dp(i)) % mod
        }
        ans
    }
}

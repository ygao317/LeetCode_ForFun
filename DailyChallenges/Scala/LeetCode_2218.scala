object Solution {
    def maxValueOfCoins(piles: List[List[Int]], K: Int): Int = {
        val n = piles.length
        val memo = Array.ofDim[Int](n+1, K+1)
        def dp(i: Int, k: Int): Int = {
            if (memo(i)(k)>0) memo(i)(k) else if (i == n || k == 0) 0 else {
                var res = dp(i+1, k)
                var cur = 0
                for (j <- 0 until (piles(i).length min k)){
                    cur += piles(i)(j)
                    res = Math.max(res, dp(i+1, k-j-1) + cur)
                }
                memo(i)(k) = res;
                res
            }
        }
        dp(0, K)
    }
}

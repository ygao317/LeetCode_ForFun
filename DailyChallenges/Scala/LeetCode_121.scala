object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        var lmax = 0; var ans = 0;
        for (i <- 1 until prices.length){
            lmax += prices(i)-prices(i-1)
            lmax = Math.max(0, lmax)
            ans = math.max(ans, lmax);
        }
        ans
    }
}

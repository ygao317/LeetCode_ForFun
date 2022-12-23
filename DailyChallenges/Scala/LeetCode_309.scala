object Solution {
    def maxProfit(prices: Array[Int]): Int = if (prices.length <= 1) 0 else {
        val (s1, _, s3) = prices.tail.foldLeft((0, -prices.head, Int.MinValue))(
            (t, price) => (Math.max(t._1, t._3), Math.max(t._2, t._1 - price), t._2 + price)
        );
        Math.max(s1, s3)
    }
}

object Solution {
    def kidsWithCandies(candies: Array[Int], extraCandies: Int): List[Boolean] = {
        val mx = candies.max
        candies.map(_ + extraCandies >= mx).toList
    }
}

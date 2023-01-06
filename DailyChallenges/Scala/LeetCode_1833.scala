object Solution {
    def maxIceCream(costs: Array[Int], coins: Int): Int = {
        var count = 0
        costs.sorted.foldLeft(coins)( (left, i) => if (left >= i) { count += 1; (left - i)} else return count)
        count // case when you got a large amount of money can buy all
    }
}

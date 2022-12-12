object Solution {
    def climbStairs(n: Int): Int = {
        val steps = Array(1, 2)
        if (n <= 2) return steps(n-1)
        for (_ <- 3 to n){ val nxt = steps(0) + steps(1); steps(0) = steps(1); steps(1) = nxt}
        steps(1)
    }
}

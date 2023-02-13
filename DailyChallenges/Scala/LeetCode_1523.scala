object Solution {
    def countOdds(low: Int, high: Int): Int = {
        val q = (high-low) / 2
        if (high%2 ==0 && low%2 ==0) q else (q+1)
    }
}

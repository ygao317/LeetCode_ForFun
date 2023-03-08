object Solution {
    def minEatingSpeed(piles: Array[Int], h: Int): Int = {
        def check(k: Int): Boolean = {
            piles.foldLeft(0)((s, p) => {
                val _s = s + (p+k-1)/k
                if (_s > h) return true
                _s
            })
            false
        }

        def bs(l: Int, r: Int): Int = if (l>=r) l else {
            val m = l + (r-l)/2
            if (check(m)) bs(m+1,r) else bs(l, m)
        }

        bs(1, 1e9.toInt)
    }
}

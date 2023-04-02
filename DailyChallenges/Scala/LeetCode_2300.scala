object Solution {
    def successfulPairs(spells: Array[Int], potions: Array[Int], success: Long): Array[Int] = {
        val p = potions.sorted

        def bs(t: Int, l:Int = 0, r: Int = p.length): Int ={
            if (l>=r) return l
            val m = l + (r-l)/2;
            if (p(m)*t.toLong >= success) bs(t, l, m) else bs(t, m+1, r)
        }
        spells.map(sp => p.length - bs(sp))
    }
}

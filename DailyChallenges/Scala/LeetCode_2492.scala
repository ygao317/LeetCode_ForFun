object Solution {
    def minScore(n: Int, roads: Array[Array[Int]]): Int = {
        val p = (0 to n).toArray
        val d = Array.fill[Int](n+1)(Int.MaxValue)

        def find(a: Int): Int = if (p(a) == a) a else {
            p(a) = find(p(a))
            p(a)
        }

        def union(r:Array[Int]): Unit = {
            val p1 = find(r(0))
            val p2 = find(r(1))
            if (p1 != p2) p(p2) = p1
        }

        for (r <- roads){
            union(r)
            d(r(0)) = Math.min(d(r(0)), r(2))
            //d(r(1)) = Math.min(d(r(1)), r(2))
        }

        var ans = Int.MaxValue
        for (i<- 1 to n if find(p(i)) == find(p(1)))
            ans = Math.min(ans, d(i))

        ans
    }
}

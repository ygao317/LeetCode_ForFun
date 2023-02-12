object Solution {
    def minimumFuelCost(roads: Array[Array[Int]], seats: Int): Long = {
        val n = roads.length+1
        val e = Array.fill[List[Int]](n)(Nil)
        for (a <- roads){
            e(a(0)) = a(1) :: e(a(0))
            e(a(1)) = a(0) :: e(a(1))
        }

        var ans:Long = 0L
        def dfs(i: Int, pre: Int, depth: Int): Int = {
            var riders = 1
            for (j <- e(i) if j != pre)
                riders += dfs(j, i, depth + 1)
            if (depth == 0) 0 else {
                ans += (riders / seats) * depth + (if (riders % seats == 0) 0 else 1)
                riders % seats
            }
        }

        dfs(0, -1, 0)
        ans
    }
}

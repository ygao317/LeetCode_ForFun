object Solution {
    def rob(nums: Array[Int]): Int = {
        val (s1,s2) = nums.foldLeft((0,0))((p, n) => (p._2, math.max(p._1 + n, p._2)))
        math.max(s1,s2)
    }
}

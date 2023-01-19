object Solution {
    def subarraysDivByK(nums: Array[Int], k: Int): Int = {
        val cnt = Array.ofDim[Int](k); cnt(0) = 1
        val (_, ans) = nums.foldLeft((0,0))((p, n) => {
            val prefix = (p._1 + n % k + k) % k
            cnt(prefix) = cnt(prefix) + 1
            (prefix, p._2 + cnt(prefix)-1)
        })
        ans
    }
}

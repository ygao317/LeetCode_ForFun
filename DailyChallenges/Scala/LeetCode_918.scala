object Solution {
    def maxSubarraySumCircular(nums: Array[Int]): Int = {
        val (curMax, maxSum, curMin, minSum, total) = nums.foldLeft((0, nums(0), 0, nums(0), 0))((t,a) => {
            val curMax = Math.max(t._1 + a, a)
            val curMin = Math.min(t._3 + a, a)
            (curMax, Math.max(curMax, t._2), curMin, Math.min(curMin, t._4), t._5 + a)
        })

        if (maxSum > 0) Math.max(maxSum, total - minSum) else maxSum
    }
}

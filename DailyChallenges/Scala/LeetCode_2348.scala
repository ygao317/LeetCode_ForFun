object Solution {
    def zeroFilledSubarray(nums: Array[Int]): Long = {
        def helper(i: Int, cnt: Long, lc: Long): Long = if (i == nums.length) cnt else {
            if (nums(i) == 0) helper(i+1, cnt+lc+1, lc+1) else helper(i+1, cnt, 0)
        }
        helper(0, 0, 0)
    }
}

object Solution {
    def jump(nums: Array[Int]): Int = {
        val n = nums.length
        def loop(i: Int = 0, jumps: Int = 0, end: Int = 0, farthest: Int = 0): Int = if (i == n-1) jumps else {
            val _farthest = farthest max (i+nums(i)) 
            if (i == end)
                loop(i+1, jumps+1, _farthest, _farthest)
            else
                loop(i+1, jumps, end, _farthest)
        }
        loop()
    }
}

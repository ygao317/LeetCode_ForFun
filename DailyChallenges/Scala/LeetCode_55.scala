object Solution {
    def canJump(nums: Array[Int]): Boolean = {
        var reach = 0
        for (i <- 0 until nums.length){
            if (i>reach) return false
            reach = Math.max(i+nums(i), reach)
        }
        true
    }
}

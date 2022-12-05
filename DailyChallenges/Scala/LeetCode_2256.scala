object Solution {
    def minimumAverageDifference(nums: Array[Int]): Int = {
        var pre:Long = 0L; var post:Long = nums.foldLeft(0L)(_+_)
        var ans = -1; var diff = Long.MaxValue
        val n = nums.length
        for (i <- 0 until n){
            pre = pre + nums(i)
            post = post - nums(i)
            val ldiff = math.abs(pre/(i+1) - (if (i==n-1) 0 else post/(n-i-1))) 
            if (ldiff < diff){
                ans = i 
                diff = ldiff
            }
        }
        ans
    }
}

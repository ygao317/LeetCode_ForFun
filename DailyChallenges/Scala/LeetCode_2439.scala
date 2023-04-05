object Solution {
    def minimizeArrayValue(nums: Array[Int]): Int = {
        var minmax = 0L; var sum = 0L
        for (i<- 0 until nums.length){
            sum += nums(i)
            minmax = ((sum + i) / (i+1)) max minmax
        }
        minmax.toInt
    }
}

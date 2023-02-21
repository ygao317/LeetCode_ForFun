object Solution {
    def singleNonDuplicate(nums: Array[Int]): Int = {
        var l = 0; var r = nums.length
        while (l+1 < r){
            val m = (l+r)/2
            if (m%2 == 0 && nums(m) == nums(m+1)) l = m
            else if (m%2 == 1 && nums(m-1) == nums(m)) l = m+1
            else if (m%2 == 0) r = m+1
            else r = m
        }
        nums(l)
    }
}

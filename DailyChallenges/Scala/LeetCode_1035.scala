object Solution {
    def maxUncrossedLines(nums1: Array[Int], nums2: Array[Int]): Int = {
        val dp = Array.ofDim[Int](nums1.length+1, nums2.length+1)
        for (i <- 1 to nums1.length; j<- 1 to nums2.length){
            if (nums1(i-1) == nums2(j-1))
                dp(i)(j) = dp(i-1)(j-1) + 1
            else
                dp(i)(j) = dp(i)(j-1) max dp(i-1)(j)
        }
        dp(nums1.length)(nums2.length)
    }
}

object Solution {
    def numSubseq(nums: Array[Int], target: Int): Int = {
        val snums = nums.sorted
        val pows = Array.fill[Int](nums.length-1)(0).scanLeft(1)(_ * 2 % 1000000007 + _)
        
        def helper(l: Int, r: Int, res: Int): Int = 
            if (l > r) res
            else if (snums(l) + snums(r) > target) 
                helper(l, r-1, res)
            else
                helper(l+1, r, (res + pows(r-l)) % 1000000007)

        helper(0, nums.length-1, 0)
    }
}

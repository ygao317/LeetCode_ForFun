object Solution {
    def countSubarrays(nums: Array[Int], minK: Int, maxK: Int): Long = {
        def helper(jbad: Int, jmin: Int, jmax: Int, i: Int, res: Long): Long = {
            if (i>= nums.length) res else {
                val _jbad = if (nums(i) < minK || nums(i) > maxK) i else jbad
                val _jmin = if (nums(i) == minK) i else jmin
                val _jmax = if (nums(i) == maxK) i else jmax
                val _res = res + Math.max(0L, Math.min(_jmin, _jmax) - _jbad)
                helper(_jbad, _jmin, _jmax, i+1, _res)
            } 
        }
        helper(-1, -1, -1, 0, 0L)
    }
}

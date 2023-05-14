object Solution {
    def maxScore(nums: Array[Int]): Int = {
        val n = nums.length
        val m = 1 << n
        val dp = Array.fill[Int](m)(0) // the mask

        // helper function
        def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a%b)
        def bitCount(i: Int, c: Int = 0): Int = if (i == 0) c else bitCount(i/2, c + i%2)
        
        // let us bottom up 
        for (mask <- Range(0, m); c = bitCount(mask) if c%2 == 0; k = c/2 + 1;
             i <- Range(0,n); i_m = 1<<i; j <- Range(i+1, n); j_m = 1<<j;
             if (mask & i_m) + (mask & j_m) == 0; nextMask = mask | i_m | j_m)
            dp(nextMask) = dp(nextMask) max (dp(mask) + k * gcd(nums(i), nums(j)))
    
        dp(m-1)    
    }
}

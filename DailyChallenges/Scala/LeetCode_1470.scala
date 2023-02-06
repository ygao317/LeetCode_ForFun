object Solution {
    def shuffle(nums: Array[Int], n: Int): Array[Int] = {
        val ans = Array.ofDim[Int](2*n)
        for (i <- 0 until 2*n; j = if (i<n) 2*i else 2*(i-n)+1)
            ans(j) = nums(i)
        ans
    }
}

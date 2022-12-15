object Solution {
    def longestCommonSubsequence(text1: String, text2: String): Int = {
        val n1 = text1.length; val n2 = text2.length
        if (n1 > n2) longestCommonSubsequence(text2, text1) else {
            val m = Array(Array.ofDim[Int](n1+1), Array.ofDim[Int](n1+1))
            for (j <- 0 until n2; i <- 0 until n1; idx = (j+1)%2){
                if (text1(i) == text2(j)) 
                    m(idx)(i+1) = 1 + m(1-idx)(i)
                else
                    m(idx)(i+1) = math.max(m(1-idx)(i+1), m(idx)(i))
            }
            m(n2%2)(n1)
        }
    }
}

object Solution {
    def numWays(words: Array[String], target: String): Int = {
        val n = target.length
        val mod = 1000000007
        val res = Array.fill[Long](n+1)(0); res(0) = 1
        for (i <- 0 until words(0).length){
            val cnt = Array.fill[Int](26)(0)
            for (w <-words) cnt(w(i) - 'a') += 1
            for (j <- n-1 to 0 by -1)
                res(j+1) += res(j) * cnt(target(j) - 'a') % mod
        }
        (res(n) % mod).toInt
    }
}

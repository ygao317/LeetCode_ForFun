object Solution {
    def ways(pizza: Array[String], k: Int): Int = {
        val m = pizza.length
        val n = pizza(0).length
        val ac = Array.ofDim[Int](m+1,n+1)
        val dp = Array.ofDim[Int](k, m, n)

        for (r <- m-1 to 0 by -1; c <- n-1 to 0 by -1){
            ac(r)(c) = (if (pizza(r)(c) == 'A') 1 else 0) + ac(r+1)(c) + ac(r)(c+1) - ac(r+1)(c+1)
            dp(0)(r)(c) = if (ac(r)(c)>0) 1 else 0
        }

        val mod = 1000000007
        for (s <- 1 until k; r <- 0 until m; c <- 0 until n){
            for (_r <- r+1 until m if ac(r)(c) > ac(_r)(c))
                dp(s)(r)(c) = (dp(s)(r)(c) + dp(s-1)(_r)(c)) % mod
            for (_c <- c+1 until n if ac(r)(c) > ac(r)(_c))
                dp(s)(r)(c) = (dp(s)(r)(c) + dp(s-1)(r)(_c)) % mod
        }

        dp(k-1)(0)(0)
    }
}

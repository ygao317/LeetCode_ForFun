object Solution {
    def tribonacci(n: Int): Int = {
        val a = Array(0, 1, 1)
        if (n < 3) return a(n)
        
        for (i <- 3 to n){
            val s = a.sum; a(0) = a(1); a(1) = a(2); a(2) = s
        }
        a(2) 
    }
}

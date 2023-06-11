object Solution {
    def maxValue(n: Int, index: Int, maxSum: Int): Int = {
        def spread(l: Int, r: Int, c: Int, left: Int): Int = {
            val base = r - l + 1
            if (base == n) c + left / base // can spreed up once base = n
            else if (left < base) c 
            else spread(if (l > 0) l-1 else l, if (r < n-1) r+1 else r, c + 1, left - base)
        }
        
        spread(index, index, 1, maxSum - n)
    }
}

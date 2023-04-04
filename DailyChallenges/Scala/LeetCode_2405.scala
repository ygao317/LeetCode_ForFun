object Solution {
    def partitionString(s: String): Int = {
        val chs = Array.fill[Int](26)(0)
        var ans = 1
        for (ch <- s){
            if (chs(ch-'a') == ans) ans += 1
            chs(ch-'a') = ans
        }
        ans
    }
}

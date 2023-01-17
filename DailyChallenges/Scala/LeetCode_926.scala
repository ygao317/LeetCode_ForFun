object Solution {
    def minFlipsMonoIncr(s: String): Int = {
        val f0 = s.scanLeft(0)((cnt, ch) => if (ch == '0') cnt else cnt+1).tail
        val f1 = s.scanRight(0)((ch, cnt) => if (ch == '1') cnt else cnt+1).init
        (f0 zip f1).map(p => p._1 + p._2 -1).min
    }
}

object Solution {
    def restoreIpAddresses(s: String): List[String] = {
        var ans = List.empty[String]
        val n = s.length
        def dfs(l: List[Int], i: Int): Unit = {
            if (l.length > 4) return
            if (i == n){
                if (l.length < 4) return
                ans = l.reverse.mkString(".") :: ans
            }else{
                val digit = s(i).asDigit
                if (l.length < 4)
                    dfs(digit :: l, i+1)
                
                val seg = l.head * 10 + digit
                if (seg <= 255 && l.head != 0)
                    dfs(seg :: l.tail, i+1)
            }
        }
        dfs(s(0).asDigit :: Nil, 1)
        ans
    }
}

object Solution {
    def minTime(n: Int, edges: Array[Array[Int]], hasApple: List[Boolean]): Int = {
        val m = scala.collection.mutable.HashMap.empty[Int, List[Int]]
        for (e <- edges){
            m(e(0)) = e(1) :: m.getOrElse(e(0), Nil)
            m(e(1)) = e(0) :: m.getOrElse(e(1), Nil)
        }
        val hasApp = hasApple.toArray
        var ans = 0
        def cntTime(node:Int, p: Int): Boolean = {
            var ha = hasApp(node)
            for (ch <- m(node) if ch != p; cha = cntTime(ch, node)){
                if (cha) ans += 1
                ha = ha | cha
            }
            ha
        }
        cntTime(0,-1)
        ans*2
    }
}

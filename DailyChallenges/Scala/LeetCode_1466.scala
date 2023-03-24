object Solution {
    def minReorder(n: Int, connections: Array[Array[Int]]): Int = {
        val m = Array.fill[List[Int]](n)(Nil)
        for (a <- connections) {
            m(a(0)) = a(1) :: m(a(0)) // st -> ed
            m(a(1)) = -a(0) :: m(a(1)) // ed -> -st
        }

        val vt = Array.fill[Boolean](n)(false)

        def dfs(st: Int): Int = {
            var change = 0
            vt(st) = true
            for (ed <- m(st) if !vt(Math.abs(ed))){
                if (ed > 0) change += 1
                change += dfs(Math.abs(ed))
            }
            change
        }

        dfs(0)
    }
}

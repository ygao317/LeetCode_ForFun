object Solution {
    def makeConnected(n: Int, connections: Array[Array[Int]]): Int = {
        if (connections.length < n-1) return -1;

        val p = (0 until n).toArray
        def find(i: Int): Int = if (p(i) == i) i else {
            p(i) = find(p(i))
            p(i)
        }

        for (c <- connections){
            val i1 = find(c(0))
            val i2 = find(c(1))
            if (i1 != i2) p(i1) = i2
        }

        (0 until n).count(i => find(i) == i) - 1;
    }
}

object Solution {
    def countPairs(n: Int, edges: Array[Array[Int]]): Long = {
        val p = (0 until n).toArray
        def find(i: Int): Int = {
            if (p(i) != i) p(i) = find(p(i))
            p(i)
        }

        for (e<-edges){
            val i1 = find(e(0))
            val i2 = find(e(1))
            if (i1 != i2) p(i1) = i2
        }

        val m = collection.mutable.Map.empty[Int, Int]
        for (i <- 0 until n; _i = find(i))
            m(_i) = m.getOrElse(_i, 0) + 1
        
        m.foldLeft((0L,n))((ap, kp) => (ap._1 + kp._2.toLong * (ap._2-kp._2), ap._2-kp._2))._1
    }
}

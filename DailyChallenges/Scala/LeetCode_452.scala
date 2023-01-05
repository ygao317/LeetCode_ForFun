object Solution {
    def findMinArrowShots(points: Array[Array[Int]]): Int = {
        val sps = points.sortWith((a1,a2) => a1(0)<a2(0) || (a1(0) == a2(0) && a1(1) < a2(1)))
        sps.tail.foldLeft((sps.head(1), 1))((r, p) => if (p(0)>r._1) (p(1), r._2+1) else (math.min(r._1, p(1)), r._2))._2
    }
}

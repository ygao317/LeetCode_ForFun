object Solution {
    def maxPoints(points: Array[Array[Int]]): Int = {
        var ans = 0
        for (i <- 0 until points.length){
            val cnt = collection.mutable.Map.empty[Double, Int]
            for (j <- 0 until points.length if i != j){
                if (points(i)(0) == points(j)(0))
                    cnt(Int.MaxValue) = cnt.getOrElse(Int.MaxValue, 0) + 1
                val rate = (points(i)(1) - points(j)(1)).toDouble / (points(i)(0) - points(j)(0));
                cnt(rate) = cnt.getOrElse(rate, 0) + 1
            }
            for (c<-cnt.values)
                ans = Math.max(c, ans)
        }
        ans+1
    }
}

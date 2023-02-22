object Solution {
    def shipWithinDays(weights: Array[Int], days: Int): Int = {
        var left = weights.reduceLeft(_ max _)
        var right = 25000000
        while (left < right) {
            val mid = (left+right)/2
            val need = weights.foldLeft((0, 1)){(p, w) => if (w + p._1 <= mid) (p._1+w, p._2) else (w, p._2+1)}._2
            if (need > days) left = mid+1 else right = mid
        }
        left
    }
}

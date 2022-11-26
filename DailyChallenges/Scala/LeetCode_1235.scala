object Solution {
    def jobScheduling(startTime: Array[Int], endTime: Array[Int], profit: Array[Int]): Int = {
        val dp = collection.mutable.SortedMap.empty[Int, Int]; dp(0) = 0
        for ((e, s, p) <- (endTime, startTime, profit).zipped.toList.sorted){
            val doit = dp.maxBefore(s+1).get._2 + p
            if (doit > dp.last._2) dp(e) = doit
        }
        dp.last._2
    }
}

object Solution {
    def answerQueries(nums: Array[Int], queries: Array[Int]): Array[Int] = {
        val preSum = nums.sorted.scanLeft(0)(_+_)
        import scala.collection.Searching._
        queries.map(preSum.search(_) match {
            case Found(i) => i
            case InsertionPoint(i) => i-1
        })
    }
}

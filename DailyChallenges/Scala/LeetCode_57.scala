object Solution {
    def insert(intervals: Array[Array[Int]], newInterval: Array[Int]): Array[Array[Int]] = {
        import scala.collection.Searching._
        val st = intervals.map(_(0)).search(newInterval(0)) match {
            case Found(i) => i
            case InsertionPoint(i) => if (i>0 && intervals(i-1)(1) >= newInterval(0)){
                newInterval(0) = intervals(i-1)(0)
                i-1 } else i          
        }
        val ed = intervals.map(_(1)).search(newInterval(1)) match {
            case Found(i) => i+1
            case InsertionPoint(i) => if (i< intervals.length && intervals(i)(0) <= newInterval(1)){
                newInterval(1) = intervals(i)(1)
                i+1 } else i
        }
        // [st, ed) should be replaced by newInterval
        val ans = Array.ofDim[Array[Int]](intervals.length - (ed-st)+1)
        Array.copy(intervals, 0, ans, 0, st)
        ans(st) = newInterval
        Array.copy(intervals, ed, ans, st+1, intervals.length - ed)
        ans
        // above Array copy save some memory from temperate Arrays
        // intervals.slice(0, st) appended newInterval concat intervals.slice(ed, intervals.length)
    }
}

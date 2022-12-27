object Solution {
    def maximumBags(capacity: Array[Int], rocks: Array[Int], additionalRocks: Int): Int = {
        var ans = 0
        var extra = additionalRocks
        for (slot <- capacity.zip(rocks).map(t => t._1 - t._2).sorted if extra >= slot){
            extra -= slot
            ans += 1
        }
        ans
    }
}

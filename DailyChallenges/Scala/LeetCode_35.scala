object Solution {
    def searchInsert(nums: Array[Int], target: Int): Int = {
        import collection.Searching._
        nums.search(target) match {case InsertionPoint(i) => i case Found(i) => i}
    }
}

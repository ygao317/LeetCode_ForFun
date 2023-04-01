object Solution {
    def search(nums: Array[Int], target: Int): Int = {
        import collection.Searching._
        nums.search(target) match { case Found(i) => i; case InsertionPoint(_) => -1}
    }
}

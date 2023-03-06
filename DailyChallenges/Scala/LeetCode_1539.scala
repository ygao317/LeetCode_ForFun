object Solution {
    def findKthPositive(arr: Array[Int], k: Int): Int = {
        val left = ((1 to (arr.length + k)).toSet -- arr.toSet).toArray.sorted
        left(k-1)
    }
}

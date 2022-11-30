object Solution {
    def uniqueOccurrences(arr: Array[Int]): Boolean = {
        val vs = arr.groupMapReduce(identity)(_=>1)(_ + _).values
        vs.size == vs.toSet.size
    }
}

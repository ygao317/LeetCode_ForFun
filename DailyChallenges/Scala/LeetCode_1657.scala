object Solution {
    def closeStrings(word1: String, word2: String): Boolean = {
        if (word1.length != word2.length) false else {
            val p1 = word1.toList.groupMapReduce(identity)(_ => 1)(_+_)
            val p2 = word2.toList.groupMapReduce(identity)(_ => 1)(_+_)
            
            p1.size == p2.size && p1.keySet == p2.keySet && p1.values.toList.sorted == p2.values.toList.sorted
        }
    }
}

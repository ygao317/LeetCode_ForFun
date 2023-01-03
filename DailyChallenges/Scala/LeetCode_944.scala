object Solution {
    def minDeletionSize(strs: Array[String]): Int = {
        strs.map(_.toArray).transpose.count(a => !(a.sorted sameElements a))
    }
}

object Solution {
    def isAlienSorted(words: Array[String], order: String): Boolean = {
        val n = words.length
        if (n == 1) return true
        
        val dict = order.zipWithIndex.toMap

        def check(w1: String, w2: String): Boolean = 
            if (w1.isEmpty) true 
            else if (w1.nonEmpty && w2.isEmpty) false
            else {
                val (s1, s2) = (dict(w1.head), dict(w2.head))
                if (s1 == s2) check(w1.tail, w2.tail) else if (s1 < s2) true else false             
            }

        for (i <- Range(1,n); w1 = words(i-1); w2 = words(i))
            if (!check(w1, w2)) return false
        
        true
    }
}

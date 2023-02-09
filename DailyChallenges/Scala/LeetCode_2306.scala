object Solution {
    def distinctNames(ideas: Array[String]): Long = {
        import collection.mutable.HashSet
        val m = Array.fill[HashSet[String]](26)(HashSet.empty[String])
        for (s <- ideas)
            m(s.head - 'a') += s.drop(1)

        var ans: Long = 0L
        for (i <- 0 until 26; j<- i+1 until 26)
            ans += (m(i) diff m(j)).size * (m(j) diff m(i)).size
        ans * 2
    }
}

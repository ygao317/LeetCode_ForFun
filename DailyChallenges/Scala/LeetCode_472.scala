object Solution {
    def findAllConcatenatedWordsInADict(words: Array[String]): List[String] = {
        val set = scala.collection.mutable.HashSet.empty[String]

        def dfs(word: String, i: Int): Boolean = if (i == word.length) true else {
            for (j <- i+1 to word.length if set.contains(word.slice(i,j))){
                if (dfs(word, j)) return true
            }
            false
        } 

        var ans: List[String] = Nil
        for (w <- words.sortBy(_.length)){
            if (dfs(w, 0)) 
                ans = w :: ans
            else
                set.add(w)
        }
        
        ans
    }
}

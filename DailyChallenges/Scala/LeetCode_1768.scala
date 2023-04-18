object Solution {
    def mergeAlternately(word1: String, word2: String): String = {
        val n1 = word1.length
        val n2 = word2.length
        
        val reminder = if (n1 > n2) word1.slice(n2, n1) else word2.slice(n1, n2)
        word1.zip(word2).foldLeft(""){ (s, p) => s + p._1 + p._2 } + reminder
    }
}

object Solution {
    def halvesAreAlike(s: String): Boolean = {
        def isVowel(c: Char): Boolean = List('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U') contains c
        s.splitAt(s.length/2) match { case (h1, h2) => h1.count(isVowel) == h2.count(isVowel) }
    }
}

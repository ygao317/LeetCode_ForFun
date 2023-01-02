object Solution {
    def detectCapitalUse(word: String): Boolean = {
        word.substring(1).forall(_.isLower) || word.forall(_.isUpper)
    }
}

class Trie() {
  val children = collection.mutable.Map.empty[Char, Trie]
  var isTerminal = false

  def insert(word: String) = word.foldLeft(this) { case (t, c) => t.children.getOrElseUpdate(c, new Trie()) }.isTerminal = true

  def search(word: String): Boolean =
    if( word == "") isTerminal
    else if (word.head == '.'){
        for (ch <- children){
            val find = ch._2.search(word.tail)
            if (find) return true;
        }
        false
    } else if( children.contains(word.head) ) children(word.head).search(word.tail)
    else false
}

class WordDictionary() {
    val trie = new Trie()

    def addWord(word: String) {
        trie.insert(word)
    }

    def search(word: String): Boolean = {
        trie.search(word)
    }

}

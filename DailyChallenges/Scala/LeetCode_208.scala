class Trie() {
  val children = collection.mutable.Map.empty[Char, Trie]
  var isTerminal = false

  def insert(word: String) = word.foldLeft(this) { case (t, c) => t.children.getOrElseUpdate(c, new Trie()) }.isTerminal = true

  def search(word: String): Boolean =
    if( word == "") isTerminal
    else if( children.contains(word.head) ) children(word.head).search(word.tail)
         else false

  def startsWith(prefix: String): Boolean =
    if( prefix == "") true
    else if( children.contains(prefix.head)) children(prefix.head).startsWith(prefix.tail)
         else false
}

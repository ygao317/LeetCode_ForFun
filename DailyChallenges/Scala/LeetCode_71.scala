object Solution {
    def simplifyPath(path: String): String = {
        val elems = path.split('/')
        val n = elems.length
        
        def parse(i:Int, l:List[String]): String = {
            if (i == n) "/" + l.reverse.mkString("/")
            else {
                val e = elems(i)
                e match {
                    case "" => parse(i+1, l)
                    case "." => parse(i+1, l)
                    case ".." => parse(i+1, if (l.isEmpty) l else l.tail)
                    case _ => parse(i+1, e :: l)
                }
            }
        }
        
        parse(0, List.empty[String])
    }
}

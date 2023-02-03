object Solution {
    def convert(s: String, numRows: Int): String = {
        if (numRows == 1 || numRows == s.length) s else {
            val a = Array.fill[List[Char]](numRows)(Nil)
            val g = numRows * 2 - 2 
            
            for (i <- 0 until s.length; c = i % g; r = if (c < numRows) c else (g-c))
                a(r) = s(i) :: a(r)
            
            a.foldLeft(""){(s, l) => s + l.reverse.mkString}
        }
    }
}

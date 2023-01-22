object Solution {
    def partition(s: String): List[List[String]] = {
        val n = s.length
        def isPalindrome(i:Int, j:Int): Boolean = {
            if (i==j || j==i+1) 
                true
            else 
                if (s(i) == s(j-1)) isPalindrome(i+1,j-1) else false
        }
        
        def toStringList(i: Int): List[String] = {
            val start = i.toBinaryString.zipWithIndex.filter(_._1 == '1').map(_._2).toList
            val end = start.tail.appended(n)
            start.zip(end).map(p => s.slice(p._1,p._2))
        }
        
        val m = Array.ofDim[List[Int]](n+1,n+1)
        for {   l <- Range(1, n+1) // l = 1 to n-1
                i <- Range(0, n)
                j = i + l if j<=n }{
            m(i)(j) = (for { k <- Range(i+1, j)
                             x <- m(i)(k)
                             y <- m(k)(j)}
                yield ((x << (j-k)) + y)).toSet.toList
            
            if (isPalindrome(i,j))
                m(i)(j) = m(i)(j).appended(1<<(j-i-1))
            //println("i, j, m", i, j, m(i)(j))
            
        }
        
        m(0)(n).map(toStringList)
    }
}

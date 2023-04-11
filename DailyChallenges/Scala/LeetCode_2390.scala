object Solution {
    def removeStars(s: String): String = {
        val sb = new scala.collection.mutable.StringBuilder(s)
        var j = 0
        for (i <- 0 until sb.length){
            if (sb(i) == '*') j-=1 else{
                sb(j) = sb(i)
                j+=1
            }
        }
        sb.substring(0,j)
    }
}

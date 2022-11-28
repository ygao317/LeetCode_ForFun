object Solution {
    def findWinners(matches: Array[Array[Int]]): List[List[Int]] = {
        import scala.collection.mutable.SortedSet
        val ws = SortedSet.empty[Int]; val ls = SortedSet.empty[Int]; val mls = SortedSet.empty[Int]
        for (Array(w,l) <- matches){
            ws += w
            if (ls contains l) mls += l else ls += l
        }
        
        (ws diff ls).toList :: (ls diff mls).toList :: Nil
    }
}

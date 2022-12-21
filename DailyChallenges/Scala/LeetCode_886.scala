object Solution {
    def possibleBipartition(n: Int, dislikes: Array[Array[Int]]): Boolean = {
        import scala.collection.mutable.{Map, Queue}
        val m = Map.empty[Int, List[Int]]
        for (e <- dislikes){
            m(e(0)) = e(1) :: m.getOrElse(e(0), Nil)
            m(e(1)) = e(0) :: m.getOrElse(e(1), Nil)
        }

        val cols = Array.ofDim[Int](n+1)
        for (i <- 1 to n if cols(i) == 0 && m.contains(i)){
            val q = Queue.empty[Int]; q.enqueue(i)
            var c = 1; cols(i) = c
            while (q.nonEmpty){
                val sz = q.length; c = -c;
                for (j <- 0 until sz; l = q.dequeue; dl <- m(l)){
                    if (cols(dl) == cols(l)) return false
                    if (cols(dl) == 0){
                        cols(dl) = c;
                        q.enqueue(dl);
                    } 
                }
            }
        }
        true
    }
}

object Solution {
    def validPath(n: Int, edges: Array[Array[Int]], start: Int, end: Int): Boolean = {
        if (start == end) return true
        val g = collection.mutable.HashMap.empty[Int,List[Int]]
        for (a <- edges){
            g(a(0)) = a(1) :: g.getOrElse(a(0),Nil)
            g(a(1)) = a(0) :: g.getOrElse(a(1),Nil)
        }
        
        val reach = Array.fill[Boolean](n)(false); reach(start) = true 
        val q = collection.mutable.Queue(start)
        while (q.nonEmpty) {
            val u = q.dequeue
            for (v <- g.getOrElse(u,Nil) if !reach(v)){
                if (v == end) return true 
                q.enqueue(v)
                reach(v) = true 
            }
        }
        false
    }
}

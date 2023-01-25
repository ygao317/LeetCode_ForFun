object Solution {
    def closestMeetingNode(edges: Array[Int], node1: Int, node2: Int): Int = {
        if (node1 == node2) return node1
        val n = edges.length
        val v = Array.ofDim[Int](n); v(node1) = 1; v(node2) = -1
        val q = scala.collection.mutable.Queue.empty[Int]; q.enqueue(node1); q.enqueue(node2)
        while (q.nonEmpty){
            var l: List[Int] = Nil
            val sz = q.length
            for (i <- 0 until q.length; st = q.dequeue; ed = edges(st) if (ed != -1 && v(ed) != v(st))){
                if (v(ed) == -v(st))
                    l = ed :: l
                else{
                    v(ed) = v(st)
                    q.enqueue(ed)
                }
            }
            if (l.nonEmpty) return l.sorted.head
        }
        -1
    }
}

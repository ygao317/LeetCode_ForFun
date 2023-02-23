object Solution {
    def findMaximizedCapital(k: Int, w: Int, profits: Array[Int], capital: Array[Int]): Int = {
        val projects = (profits zip capital).sortBy(_._2)
        val pq = collection.mutable.PriorityQueue.empty[Int]
        var idx = 0
        def loop(mw: Int, cnt: Int): Int = if (cnt > k) mw else {
            while (idx < projects.length && projects(idx)._2 <= mw) {
                pq.enqueue(projects(idx)._1)
                idx += 1
            }
            if (pq.isEmpty) mw else loop(mw + pq.dequeue, cnt+1)
        }
        loop(w, 1)
    }
}

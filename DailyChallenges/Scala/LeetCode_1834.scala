object Solution {
    def getOrder(tasks: Array[Array[Int]]): Array[Int] = {
        val _tasks = tasks.zipWithIndex.sortBy(_._1(0))
        val n = _tasks.length
        val pq = collection.mutable.PriorityQueue.empty[(Int, Int)]
        
        def sim(time: Int = 0, i: Int = 0, ans: List[Int] = List()): Array[Int] = if ( i != n || pq.nonEmpty ) { // still got task to process
            if(i < n && _tasks(i)._1(0) <= time) { // pop out task can start
                pq.enqueue((-_tasks(i)._1(1),-_tasks(i)._2))
                sim(time, i + 1, ans)
            } else if (pq.isEmpty && i<n) 
                sim(_tasks(i)._1(0), i, ans)
            else {
                val (l, idx) = pq.dequeue
                sim(time - l, i, -idx :: ans)
            }
        } else ans.reverse.toArray
                
        sim()
    }
}

object Solution {
    def numRescueBoats(people: Array[Int], limit: Int): Int = {
        import scala.collection.mutable.Queue
        val q = Queue.from(people.sorted.reverse.toIterable) // sorted queue
        
        def count(c: Int): Int = if (q.isEmpty) c else {
            val first = q.dequeue
            if (q.nonEmpty && (q.last + first <= limit)) q.dropRightInPlace(1)
            count(c+1)
        }
        
        count(0)
    }
}

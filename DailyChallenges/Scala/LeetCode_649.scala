object Solution {
    def predictPartyVictory(senate: String): String = {
        val q1 = collection.mutable.Queue.empty[Int]
        val q2 = collection.mutable.Queue.empty[Int]
        for (i <- 0 until senate.length)
            if (senate(i) == 'R') q1.enqueue(i) else q2.enqueue(i)
        while (q1.nonEmpty && q2.nonEmpty){
            val r = q1.dequeue
            val d = q2.dequeue
            if (r<d) q1.enqueue(r + senate.length) else q2.enqueue(d + senate.length)
        }
        if (q1.isEmpty) "Dire" else "Radiant"
    }
}

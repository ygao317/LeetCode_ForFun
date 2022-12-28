object Solution {
    def minStoneSum(piles: Array[Int], k: Int): Int = {
        val pq = collection.mutable.PriorityQueue[Int](piles:_*)
        for (_ <- 0 until k){
            val x = pq.dequeue
            if (x == 1) return (pq.sum + 1)
            pq.enqueue((x+1)/2)
        }
        pq.sum
    }
}

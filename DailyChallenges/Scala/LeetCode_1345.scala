object Solution {
    def minJumps(arr: Array[Int]): Int = {
        val n = arr.length
        //println(n)
        var dict = arr.zipWithIndex.groupMap(_._1)(_._2) // create the dictionary
        //println(dict)
        var visited = Array.fill[Boolean](n)(false) // no need checking
        //println(visited)
        
        import scala.collection.mutable.Queue
        
        def helper(current: Queue[Int], l: Int): Int = {
            val next = Queue.empty[Int] // next queue
            while (!current.isEmpty) { // for each one in current queue
                val i = current.dequeue
                if (i==n-1) return l
                else {
                    if (i-1>=0 && !visited(i-1)) {
                        next.enqueue(i-1) // add left neighber
                        visited(i-1) = true
                    }
                    if (i+1<n && !visited(i+1)) {
                        next.enqueue(i+1)  // add right neighber
                        visited(i+1) = true
                    }
                    
                    if (dict contains arr(i)){
                        val relatives = dict(arr(i))
                        dict -= arr(i) // drop the key to save space
                        for (_i <- relatives if !visited(_i)){
                            //if (!(relatives.contains(_i-1) && relatives.contains(_i+1))) // not in between
                                next.enqueue(_i)    
                            visited(_i) = true
                        }
                    }
                }
            }
            
            helper(next, l+1)
        }
        
        helper(Queue(0), 0)
    }
}

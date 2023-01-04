object Solution {
    def minimumRounds(tasks: Array[Int]): Int = {
        tasks.groupMapReduce(identity)(_ => 1)(_ + _).foldLeft(0)((c,p)=> {
            if (p._2 == 1) return -1
            c + (if (p._2 % 3 == 0) (p._2 / 3) else (p._2 / 3 + 1))
        })  
    }
}

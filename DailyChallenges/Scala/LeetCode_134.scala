object Solution {
    def canCompleteCircuit(gas: Array[Int], cost: Array[Int]): Int = {
        val t = gas.zip(cost).map(p => p._1 - p._2).zipWithIndex.foldLeft((0,0,0))(
            (t,c)=> if (t._2 + c._1 < 0) (t._1 + c._1, 0, c._2 +1) else (t._1 + c._1, t._2 + c._1, t._3))
        if (t._1<0) -1 else t._3
    }
}

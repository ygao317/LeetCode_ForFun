object Solution {
    def findJudge(n: Int, trust: Array[Array[Int]]): Int = {
        if (n==1 && trust.length == 0) return 1
        val allTrusts = trust.groupMap(a => a(1))(a => a(0)).filter(_._2.distinct.length == n-1).keys.toSet
        val judges = allTrusts -- trust.map(_(0)).toSet
        if (judges.size == 1) judges.head else -1 
    }
}

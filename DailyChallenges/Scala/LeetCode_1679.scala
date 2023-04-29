object Solution {
    def distanceLimitedPathsExist(n: Int, edgeList: Array[Array[Int]], queries: Array[Array[Int]]): Array[Boolean] = {
        // union find set
        val parents = Range(0,n).toArray // one array
        def find(x: Int): Int = {
            var l = x :: Nil // Initiate the set with only x    // one list
            
            def helper(i: Int): Int = {
                val p = parents(i)
                if (p == i) p else { // end when parent == self
                    l = p :: l  // add to the list
                    helper(p) // find one level up
                }
            }
            
            val p = helper(x) // got the parent
            for (i <- l) parents(i) = p // set all element's parent around the path to the root
            p  // return root
        }
        
        val E = edgeList.sortBy(_(2)) // ascending order with weight
        val Q = queries.zipWithIndex.sortBy(_._1(2)) // ascending order with limit (zip with original location)
        
        
        val A = Array.fill[Boolean](queries.length)(false) // Initiate to false
        
        var idx_e = 0
        for (q <- Range(1,Q.length)) {
            while (idx_e < E.length && E(idx_e)(2) < Q(q)._1(2)){
                val start = find(E(idx_e)(0))
                val end = find(E(idx_e)(1))
                if (start != end) parents(end) = start // union it
                idx_e += 1
            }
            A(Q(q)._2) = find(Q(q)._1(0)) == find(Q(q)._1(1))
        }
        
        A
    }
}

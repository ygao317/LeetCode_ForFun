object Solution {
    def isBipartite(graph: Array[Array[Int]]): Boolean = {
        val n = graph.length 
        val coloured = Array.fill[Int](n)(0) // array of ball pending colour
        
        // helper function to color the ball
        def colour(a: Array[Int], c: Int): Unit = for (i <- a if coloured(i) == 0) {
            coloured(i) = c
            colour(graph(i), -c)
        }
        
        // colour the balls
        for {i <- Range(0, n) if coloured(i) == 0} {
            coloured(i) = 1
            colour(graph(i), -1)
        }
        
        // check if isBipartite
        graph.zipWithIndex.forall(p => p._1.forall(coloured(_) == -coloured(p._2)))
    }
}

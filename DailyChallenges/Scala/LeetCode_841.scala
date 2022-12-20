object Solution {
    def canVisitAllRooms(rooms: List[List[Int]]): Boolean = {
        // Just Search
        val n = rooms.length
        val visited = Array.fill(n)(false)
        
        def search(i: Int): Unit = for (j <- rooms(i) if !visited(j)) {
            visited(j) = true
            search(j)
        }
        
        visited(0) = true
        search(0)
        //println(visited.toList)
        visited.forall(b => b)
    }
}

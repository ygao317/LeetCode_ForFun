object Solution {
    def cloneGraph(graph: Node): Node = {
        val m = collection.mutable.HashMap.empty[Int, Node]
        def clone(node: Node): Node = {
            if (node == null) null else if (m.contains(node.value)) m(node.value) else {
                val nn = new Node(node.value)
                m(node.value) = nn
                for (n <- node.neighbors.reverse)
                    nn.neighbors = clone(n) :: nn.neighbors
                nn
            }
        }
        clone(graph)
    }
}

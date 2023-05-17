object Solution {
    def pairSum(head: ListNode): Int = {
        def toList(node: ListNode, l: List[Int]): List[Int] = if (node == null) l else toList(node.next, node.x :: l)
        val v = toList(head, Nil).toArray
        (0 until v.length/2).foldLeft(0)((m, i) => m max (v(i) + v(v.length-1-i)))
    }
}

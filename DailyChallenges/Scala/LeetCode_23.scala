object Solution {
    def mergeKLists(lists: Array[ListNode]): ListNode = {
        // convert to a big list
        def loop(xl: List[Int] = List.empty[Int]): List[Int] = {
            val _xl = lists.zipWithIndex.foldLeft(xl)((l, p) => {
                if (p._1 != null){
                    lists(p._2) = p._1.next
                    p._1.x :: l
                }else l
            })
        
            if (_xl.length == xl.length) _xl // done
            else loop(_xl)
        }
        
        val xl = loop().sorted
        if (xl.isEmpty) null else{
            val head: ListNode = new ListNode(xl.head)

            xl.tail.foldLeft(head)((node, x) => {
                val _next = new ListNode(x)
                node.next = _next
                _next
            })

            head
        }
    }
}

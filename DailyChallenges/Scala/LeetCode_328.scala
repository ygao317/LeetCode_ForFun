object Solution {
    def oddEvenList(head: ListNode): ListNode = {
        if (head == null || head.next == null) head else {
            @scala.annotation.tailrec
            def helper(node: ListNode, isOdd: Boolean, oddTail: ListNode, evenTail: ListNode): ListNode = {
                if (node == null){
                    evenTail.next = null
                    oddTail
                }else{
                    if (isOdd) oddTail.next = node else evenTail.next = node
                    helper(node.next, !isOdd, if (isOdd) node else oddTail, if (!isOdd) node else evenTail)
                }
            }

            val evenHead = head.next
            val oddTail = helper(evenHead.next, true, head, evenHead)
            oddTail.next = evenHead
            head
        }
    }
}

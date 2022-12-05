object Solution {
    def middleNode(head: ListNode): ListNode = {
        @scala.annotation.tailrec
        def helper(slow: ListNode, fast: ListNode): ListNode = 
            if (fast != null && fast.next != null) helper(slow.next, fast.next.next) else slow
        return helper(head, head)
    }
}

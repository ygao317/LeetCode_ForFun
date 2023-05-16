object Solution {
    def swapPairs(head: ListNode): ListNode = {
        
        def helper(h1: ListNode): Unit = {
            if (h1 != null && h1.next != null) {
                val tmp = h1.x
                h1.x = h1.next.x
                h1.next.x = tmp
                helper(h1.next.next)
            }
        }
        
        helper(head);
        head
    }
}

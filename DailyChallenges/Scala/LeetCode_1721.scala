object Solution {
    def swapNodes(head: ListNode, k: Int): ListNode = {
        // first pass
        def getLength(n: ListNode, c: Int): Int = if (n == null) c else getLength(n.next, c+1)
        val l = getLength(head,0)
        
        // second pass
        var skth: ListNode = null
        var ekth: ListNode = null
        def getKth(n: ListNode, i: Int): Unit = if ((skth != null & ekth != null) || n == null) return else {
            if (i == k) skth = n
            if (i == l-k+1) ekth = n
            getKth(n.next, i+1)
        }
        getKth(head,1)
        
        // swap
        val sx = skth.x
        skth.x = ekth.x
        ekth.x = sx
        head
    }
}

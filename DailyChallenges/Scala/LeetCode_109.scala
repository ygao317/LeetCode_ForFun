object Solution {
    def sortedListToBST(head: ListNode): TreeNode = {
        def toBST(h: ListNode, t: ListNode): TreeNode = {
            if (h == t) return null
            
            def move(slow: ListNode, fast: ListNode): ListNode = 
                if (fast == t || fast.next == t) slow else move(slow.next, if (fast.next == t) fast.next else fast.next.next)
            
            val half = move(h, h)
            //println(h, half, t)
            if (half == h) new TreeNode(half.x) else new TreeNode(half.x, toBST(h, half), toBST(half.next, t))
        }
        
        toBST(head, null)
    }
} 

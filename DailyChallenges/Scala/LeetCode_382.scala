class Solution(_head: ListNode) {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    

    /** Returns a random node's value. */
    def getRandom(): Int = {
        
        // recursive helper function
        def helper(s: Int, n: ListNode, v: Int): Int = {
            if (n == null)
                v // the end
            else{
                val v_ = if (scala.util.Random.nextDouble < 1.0 / s) n.x else v
                helper(s+1, n.next, v_)
            }
        } 
        
        helper(2, _head.next, _head.x)
    }
}

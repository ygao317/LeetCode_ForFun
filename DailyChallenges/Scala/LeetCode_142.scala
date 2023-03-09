object Solution {
    def detectCycle(head: ListNode): ListNode = {
        def check(s: ListNode, f: ListNode): ListNode = if (f == null || f.next == null) null else {
            val _s = s.next
            val _f = f.next.next
            if (_s == _f) _s else check(_s, _f)
        }

        val s = check(head, head)
        
        if (s == null) s else {
            def locate(r: ListNode, s: ListNode): ListNode = if (r == s) r else locate(r.next, s.next)
            locate(head, s)
        }
    }
}

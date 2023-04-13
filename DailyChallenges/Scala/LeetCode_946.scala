object Solution {
    def validateStackSequences(pushed: Array[Int], popped: Array[Int]): Boolean = {
        var stack = List.empty[Int]
        val n = pushed.length
        
        var c = 0 // count of pop
        for (num <- pushed) {
            stack = num :: stack
            while (stack.nonEmpty && c < n && stack.head == popped(c)){
                stack = stack.tail
                c += 1
            }
        }
        
        c == n
    }
}

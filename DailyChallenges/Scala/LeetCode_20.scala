object Solution {
    def isValid(s: String): Boolean = {
        def check(stack: List[Char], str: List[Char]): Boolean = if (str.isEmpty) stack.isEmpty else {
            val c = str.head
            c match {
                case '{' => check(c::stack, str.tail)
                case '[' => check(c::stack, str.tail)
                case '(' => check(c::stack, str.tail)
                case ')' => if (stack.nonEmpty && stack.head == '(') check(stack.tail, str.tail) else false
                case '}' => if (stack.nonEmpty && stack.head == '{') check(stack.tail, str.tail) else false                       
                case ']' => if (stack.nonEmpty && stack.head == '[') check(stack.tail, str.tail) else false
                case _ => check(stack, str.tail)
            }
        }
        check(List.empty[Char], s.toList)
    }
}

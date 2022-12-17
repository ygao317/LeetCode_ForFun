object Solution {
    def evalRPN(tokens: Array[String]): Int = {
        def eval(i: Int = 0, stack: List[Int] = Nil): Int = 
            if (i == tokens.length) stack.head 
            else tokens(i) match {
                case "+" => eval(i+1, (stack.tail.head + stack.head) :: stack.tail.tail)
                case "-" => eval(i+1, (stack.tail.head - stack.head) :: stack.tail.tail)
                case "*" => eval(i+1, (stack.tail.head * stack.head) :: stack.tail.tail)
                case "/" => eval(i+1, (stack.tail.head / stack.head) :: stack.tail.tail)
                case str => eval(i+1, str.toInt :: stack)
            }

        eval()
    }
}

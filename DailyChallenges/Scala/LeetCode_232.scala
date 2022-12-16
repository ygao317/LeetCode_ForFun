class MyQueue() {
    var l = List.empty[Int]

    def push(x: Int) {
        l = x :: l
    }

    def pop(): Int = {
        val x = l.last
        l = l.init
        x
    }

    def peek(): Int = {
        l.last
    }

    def empty(): Boolean = {
        l.isEmpty
    }

}

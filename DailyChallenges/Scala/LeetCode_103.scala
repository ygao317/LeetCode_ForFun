object Solution {
    def zigzagLevelOrder(root: TreeNode): List[List[Int]] = {
        val q = collection.mutable.Queue.empty[TreeNode]; q.enqueue(root)
        var ans: List[List[Int]] = Nil
        while (q.nonEmpty){
            var l: List[Int] = Nil
            for (i<- 0 until q.length; node = q.dequeue if node != null){
                l = node.value :: l
                q.enqueue(node.left)
                q.enqueue(node.right)
            }
            if (l.nonEmpty)
                ans = (if (ans.length % 2 == 0) l.reverse else l) :: ans 
        }
        ans.reverse
    }
}

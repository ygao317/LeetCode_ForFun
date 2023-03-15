object Solution {
    def isCompleteTree(root: TreeNode): Boolean = {
        val q = collection.mutable.Queue.empty[TreeNode] ; q.enqueue(root)
        var end = false
        while (q.nonEmpty){
            for (i <- 0 until q.length; node = q.dequeue){
                (end, node.left) match {
                    case (false, null) => end = true
                    case (false, _n) => q.enqueue(_n)
                    case (true, _n) if _n != null => return false
                    case _ => null
                }
                (end, node.right) match {
                    case (false, null) => end = true
                    case (false, _n) => q.enqueue(_n)
                    case (true, _n) if _n != null => return false
                    case _ => null
                }
            }
        }
        true
    }
}

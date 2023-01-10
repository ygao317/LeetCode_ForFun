object Solution {
    def isSameTree(p: TreeNode, q: TreeNode): Boolean = (p, q) match {
        case (null, null) => true
        case (null, _) => false
        case (_, null) => false
        case _ => p.value == q.value && isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
    }
}

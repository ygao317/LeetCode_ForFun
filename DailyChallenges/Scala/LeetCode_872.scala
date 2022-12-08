object Solution {
    def leafSimilar(root1: TreeNode, root2: TreeNode): Boolean = {
        def dfs(root: TreeNode): LazyList[Int] = if (root == null) LazyList.empty else {
            if (root.left == null && root.right == null)
                root.value #:: dfs(root.left) #::: dfs(root.right)
            else
                dfs(root.left) #::: dfs(root.right)
        }

        def check(l1: LazyList[Int], l2: LazyList[Int]): Boolean = (l1.isEmpty, l2.isEmpty) match {
            case (false, false) => if (l1.head == l2.head) check(l1.tail, l2.tail) else false
            case (true, true) => true
            case _ => false
        }

        check(dfs(root1), dfs(root2))
    }
}

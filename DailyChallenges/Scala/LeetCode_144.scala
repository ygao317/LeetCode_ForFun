object Solution {
    def preorderTraversal(root: TreeNode): List[Int] = {
        var nodes = List.empty[Int]
        def preorder(root: TreeNode): Unit = if (root != null){
            nodes = root.value :: nodes
            preorder(root.left)
            preorder(root.right)
        }
        preorder(root)
        nodes.reverse
    }
}

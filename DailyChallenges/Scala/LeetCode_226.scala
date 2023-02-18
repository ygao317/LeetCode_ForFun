object Solution {
    def invertTree(root: TreeNode): TreeNode = {
        if (root != null) {
            val tmp = invertTree(root.left)
            root.left = invertTree(root.right)
            root.right = tmp
        }
        root
    }
}

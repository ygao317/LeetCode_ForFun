object Solution {
    def isSymmetric(root: TreeNode): Boolean = {
        def helper(a: TreeNode, b: TreeNode): Boolean = 
            (a==null && b==null) || 
            (a != null && b!= null && a.value == b.value && 
            helper(a.left, b.right) && helper(a.right, b.left))

        helper(root, root)
    }
};

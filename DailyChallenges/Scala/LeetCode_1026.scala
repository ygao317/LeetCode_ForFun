object Solution {
    def maxAncestorDiff(root: TreeNode): Int = {
        var ans = -1
        def dfs(node: TreeNode, lmax: Int, lmin: Int): Unit = {
            val _lmax = math.max(lmax, node.value)
            val _lmin = math.min(lmin, node.value)
            if (node.left != null) dfs(node.left, _lmax, _lmin)
            if (node.right != null) dfs(node.right, _lmax, _lmin)
            if (node.left == null && node.right == null) ans = math.max(ans, _lmax - _lmin)    
        }
        dfs(root, root.value, root.value)
        ans
    }
}

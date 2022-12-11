object Solution {
    def maxPathSum(root: TreeNode): Int = {
        var ans = Int.MinValue
        def dfs(node: TreeNode): Int = if (node == null) 0 else {
            val l = math.max(0, dfs(node.left))
            val r = math.max(0, dfs(node.right))
            ans = math.max(ans, l + node.value + r);
            math.max(l, r) + node.value
        }
        dfs(root)
        ans
    }
}

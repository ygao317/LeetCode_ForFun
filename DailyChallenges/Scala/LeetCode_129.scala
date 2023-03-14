object Solution {
    def sumNumbers(root: TreeNode): Int = {
        var ans: Int = 0
        def dfs(node: TreeNode, s:Int){
            val _s = s * 10 + node.value
            if (node.left == null && node.right == null) ans += _s
            if (node.left != null) dfs(node.left, _s)
            if (node.right != null) dfs(node.right, _s)
        }
        dfs(root,0)
        ans;
    }
}

object Solution {
    def maxProduct(root: TreeNode): Int = {
        def sum(n: TreeNode): Long = if (n == null) 0L else n.value + sum(n.left) + sum(n.right)
        val total = sum(root)
        
        var ans = 0L
        def search(n: TreeNode): Long = if (n == null) 0L else {
            val s = n.value + search(n.left) + search(n.right)
            ans = ans max (s * (total - s))
            s
        }
        
        search(root)
        (ans % (1e9.toInt + 7)).toInt
    }
}

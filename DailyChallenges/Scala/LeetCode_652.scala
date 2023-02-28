object Solution {
    def findDuplicateSubtrees(root: TreeNode): List[TreeNode] = {
        val m = collection.mutable.HashMap.empty[String, Int]
        var l = List.empty[TreeNode]
        def dfs(node: TreeNode): String = if (node == null) return "" else {
            val s = "(" + dfs(node.left) + "," + node.value + "," + dfs(node.right) + ")";
            m(s) = m.getOrElse(s, 0) + 1
            if (m(s) == 2) l = node :: l
            s
        } 
        dfs(root)
        l
    }
}

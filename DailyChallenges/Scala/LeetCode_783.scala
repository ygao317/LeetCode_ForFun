object Solution {
    
    def minDiffInBST(root: TreeNode): Int = {
        var res = Int.MaxValue; var pre = -1
        def loop(t: TreeNode): Int = {
            if (t.left != null) loop(t.left)
            if (pre >= 0) res = Math.min(res, t.value - pre)
            pre = t.value
            if (t.right != null) loop(t.right)
            res
        }
        loop(root)
    }
}

import scala.util.control.TailCalls._

object Solution {
    def maxDepth(root: TreeNode): Int = {
        // helper function
        def count(c: Int, l: TreeNode, r: TreeNode): TailRec[Int] = (l, r) match {
            case (null, null) => done(c+1)
            case (null, _) => tailcall(count(c+1, r.left, r.right))
            case (_, null) => tailcall(count(c+1, l.left, l.right))
            case _ => for {
                c_l <- tailcall(count(c+1,l.left, l.right))
                c_r <- tailcall(count(c+1,r.left, r.right))
            } yield if (c_l < c_r) c_r else c_l
        }
        
        if (root == null) 0 else count(0, root.left, root.right).result
    }
}

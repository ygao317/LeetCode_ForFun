object Solution {
    def buildTree(inorder: Array[Int], postorder: Array[Int]): TreeNode = {
        def helper(ist: Int, ied: Int, pst: Int, ped: Int): TreeNode = 
            if (ist > ied || pst > ped) null else {
                var t = ist
                while (inorder(t) != postorder(ped)) t+=1
                
                val node = TreeNode(postorder(ped))
                node.left = helper(ist, t-1, pst, pst+t-ist-1)
                node.right = helper(t+1, ied, ped-(ied-t), ped-1)
                
                node
            }
        helper(0, inorder.length-1, 0, postorder.length-1)
    }
}

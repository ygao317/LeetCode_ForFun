/**
 * Definition for a QuadTree node.
 * class Node(var _value: Boolean, var _isLeaf: Boolean) {
 *   var value: Int = _value
 *   var isLeaf: Boolean = _isLeaf
 *   var topLeft: Node = null
 *   var topRight: Node = null
 *   var bottomLeft: Node = null
 *   var bottomRight: Node = null
 * }
 */

object Solution {
    def construct(grid: Array[Array[Int]]): Node = {
        def helper(up:Int, down:Int, left: Int, right: Int): Node = {
            for (i <- up until down; j <- left until right if grid(i)(j) != grid(up)(left)){
                val node = new Node(false, false)
                val midLeftRight = (left + right) / 2
                val midUpDown = (up + down) / 2
                node.topLeft = helper(up, midUpDown, left, midLeftRight)
                node.topRight = helper(up, midUpDown, midLeftRight, right)
                node.bottomLeft = helper(midUpDown, down, left, midLeftRight)
                node.bottomRight = helper(midUpDown, down, midLeftRight, right)
                return node
            }
            return new Node(grid(up)(left) == 1, true)
        }
        helper(0, grid.length, 0, grid.length)
    }
}

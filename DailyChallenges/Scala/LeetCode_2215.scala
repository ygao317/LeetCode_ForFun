object Solution {
    def findDifference(nums1: Array[Int], nums2: Array[Int]): List[List[Int]] = {
        val ans = Array.fill[List[Int]](2)(Nil)
        def helper(l1: List[Int], l2: List[Int]): Unit = {
            if (l1 == Nil && l2 == Nil) return
            if (l1 == Nil) ans(1) ++= l2
            else if (l2 == Nil) ans(0) ++= l1
            else (l1.head, l2.head) match {
                case (h1, h2) if h1 == h2 => helper(l1.tail, l2.tail)
                case (h1, h2) if h1 < h2 => ans(0) = h1 :: ans(0); helper(l1.tail, l2)
                case _ => ans(1) = l2.head :: ans(1); helper(l1, l2.tail)
            }
        }
        helper(nums1.sorted.distinct.toList, nums2.sorted.distinct.toList)
        ans.toList
    }
}

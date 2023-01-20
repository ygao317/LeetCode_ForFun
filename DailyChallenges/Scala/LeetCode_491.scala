object Solution {
    def findSubsequences(nums: Array[Int]): List[List[Int]] = {
        var ans = List.empty[List[Int]]
        
        def dfs(idx: Int, sub: List[Int]): Unit = {
            if (sub.length > 1) ans = sub.reverse :: ans
            val mark = scala.collection.mutable.HashSet.empty[Int]
            for (i <- idx until nums.length; if (sub.isEmpty || nums(i) >= sub.head) && !mark.contains(nums(i))){
                dfs(i+1, nums(i) :: sub)
                mark.add(nums(i))
            }
        }
        dfs(0, List.empty[Int])

        ans
    }
}

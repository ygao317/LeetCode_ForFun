object Solution {
    def arraySign(nums: Array[Int]): Int = {
        nums.foldLeft(1){ (p,n) => if (n == 0) return 0 else if (n>0) p else -p}
    }
}

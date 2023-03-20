object Solution {
    def canPlaceFlowers(flowerbed: Array[Int], n: Int): Boolean = {
        def helper(pre: Boolean, i: Int, n: Int): Boolean = if (n == 0) true else if (i == flowerbed.length) false else {
            if (pre && flowerbed(i) == 0 && (i == flowerbed.length-1 || flowerbed(i+1) == 0))
                helper(false, i+1, n-1)
            else
                helper(flowerbed(i) == 0, i+1, n)
        }
        helper(true, 0, n)
    }
}

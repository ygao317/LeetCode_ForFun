object Solution {
    def totalFruit(fruits: Array[Int]): Int = {
        val cnt = collection.mutable.HashMap.empty[Int,Int]
        var ans = 0; var l = 0; var r = 0
        while (r < fruits.length){
            cnt(fruits(r)) = cnt.getOrElse(fruits(r), 0) + 1
            while (cnt.size > 2){
                cnt(fruits(l)) = cnt(fruits(l)) - 1
                if (cnt(fruits(l)) == 0)
                    cnt.remove(fruits(l))
                l += 1
            }
            ans = Math.max(ans, r-l+1)
            r += 1
        }
        ans
    }
}

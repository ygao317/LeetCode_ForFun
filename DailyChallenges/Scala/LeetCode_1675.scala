object Solution {
    def minimumDeviation(nums: Array[Int]): Int = {
        import scala.collection.mutable.SortedSet
        var s = SortedSet.empty[Int]
        
        // double all odd numbers and add to set
        for (num <- nums) {
            if (num%2 == 0) s.add(num) else s.add(num*2)
        }
        
        //println(s)
        
        // apply
        var ans = Int.MaxValue
        
        while (s.last % 2 == 0) { // even number
            val m = s.last
            s -= m
            s += m/2
            ans = scala.math.min(ans, s.last - s.head)
        }

        ans
    }
}

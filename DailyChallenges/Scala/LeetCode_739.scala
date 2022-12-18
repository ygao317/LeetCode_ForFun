object Solution {
    def dailyTemperatures(temperatures: Array[Int]): Array[Int] = {
        val ans = Array.ofDim[Int](temperatures.length)
        var l = 0 :: Nil;
        for (i <- 1 until temperatures.length){
            while(l.nonEmpty && temperatures(l.head) < temperatures(i)){
                ans(l.head) = i - l.head
                l = l.tail
            }
            l = i :: l
        }
        ans
    }
}

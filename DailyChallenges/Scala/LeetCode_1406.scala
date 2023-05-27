object Solution {
    def stoneGameIII(stoneValue: Array[Int]): String = {
        val dp = Array.fill[Int](4)(0)
        for (i<- (stoneValue.length-1) to 0 by -1){
            dp(i%4) = Int.MinValue;
            var taken = 0;
            for (j <- 0 to 2 if i+j < stoneValue.length){
                taken += stoneValue(i+j)
                dp(i%4) = dp(i%4) max (taken - dp((i+j+1)%4))
            }
        }
        dp(0) match {
            case 0 => "Tie"
            case v if v>0 => "Alice"
            case _ => "Bob"
        }
    }
}

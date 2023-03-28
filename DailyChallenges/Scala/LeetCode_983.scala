object Solution {
    def mincostTickets(days: Array[Int], costs: Array[Int]): Int = {
        val travel = days.toSet
        val dp = Array.fill[Int](30)(0)
        for (i <- days.head to days.last){
            if (travel contains i) 
                dp(i%30) = (dp((i - 1) % 30) + costs(0)) min (dp(Math.max(0, i - 7) % 30) + costs(1)) min (dp(Math.max(0, i - 30) % 30) + costs(2)) 
            else
                dp(i%30) = dp((i-1)%30)
        }
        dp(days.last % 30)
    }
}

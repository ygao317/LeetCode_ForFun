object Solution {
    def average(salary: Array[Int]): Double = {
        val r = salary.foldLeft((Int.MinValue, Int.MaxValue, 0L)){(t, s) => (t._1 max s, t._2 min s, t._3 + s)}
        (r._3 - r._1 - r._2).toDouble / (salary.length - 2) 
    }
}

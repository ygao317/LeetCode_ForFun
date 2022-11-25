// 907. Sum of Subarray Minimums @ 2022/11/25

object Solution {
    def sumSubarrayMins(arr: Array[Int]): Int = {
        (0 until arr.length).foldLeft((List[Int]()), List[Int]())((p, i) => { 
            val s = p._2.dropWhile(arr(_)>arr(i)) 
            (i-s.headOption.getOrElse(-1)::p._1, i::s) // (ll, stack)
        })._1.foldLeft((0L, List[Int](), arr.length-1))((p, l) =>{
            val s = p._2.dropWhile(arr(_)>=arr(p._3))
            val r:Long = s.headOption.getOrElse(arr.length) - p._3
            ((p._1 + l*r*arr(p._3))% 1000000007, p._3::s, p._3-1) // (res, stack, idx)
        })._1.toInt
    }
}

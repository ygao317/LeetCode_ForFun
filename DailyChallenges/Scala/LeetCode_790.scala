object Solution {
    def numTilings(n: Int): Int = n match {
        case 1 => 1
        case 2 => 2
        case 3 => 5
        case _ => 
            val (_, _, ans) = (4 to n).foldLeft((1,2,5)){
                (t,_)=> (t._2, t._3, ((2*t._3.toLong + t._1)%1000000007).toInt)}
            ans
    }
}

object Solution {
    def addToArrayForm(num: Array[Int], k: Int): List[Int] = {
        def loop(i: Int, k: Int, c: Int, l: List[Int]): List[Int] = 
            if (k>0 || i>=0 || c>0){
                val _c = c + k%10 + (if (i>=0) num(i) else 0)
                loop(i-1, k/10, _c/10, _c%10 :: l)
            }else l
        loop(num.length-1, k, 0, Nil)
    }    
}

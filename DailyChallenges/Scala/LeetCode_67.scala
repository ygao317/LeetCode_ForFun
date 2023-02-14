object Solution {
    def addBinary(a: String, b: String): String = {
        if (a.length > b.length) return addBinary(b, a);
        var l: List[Int] = Nil
        var c = 0
        for ((x, y) <- a.reverse.padTo(b.length, '0') zip b.reverse){
            c = c + x.asDigit + y.asDigit
            l =  (c%2) :: l
            c = c/2
        }
        if (c==1) l = 1 :: l
        l.mkString("")
    }
}

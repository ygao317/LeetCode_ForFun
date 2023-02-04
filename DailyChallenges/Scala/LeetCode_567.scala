object Solution {
    def checkInclusion(s1: String, s2: String): Boolean = {
        val cnt = collection.mutable.Map[Char, Int]()
        cnt ++= s1.groupMapReduce(identity)(_ => 1)(_+_)

        def sliding(l: Int, r: Int): Boolean = if (r>=s2.length) false else {
            cnt(s2(r)) = cnt.getOrElse(s2(r), 0) - 1
            var _l = l
            while (cnt(s2(r)) < 0){
                cnt(s2(_l)) = cnt(s2(_l)) + 1
                _l += 1
            }
            if (r-_l+1 == s1.length) true else sliding(_l, r+1)
        }

        sliding(0, 0)
    };
}

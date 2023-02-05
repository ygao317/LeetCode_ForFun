object Solution {
    def findAnagrams(s: String, p: String): List[Int] = {
        val cnt = collection.mutable.Map[Char, Int]()
        cnt ++= p.groupMapReduce(identity)(_ => 1)(_+_)

        var ans: List[Int] = Nil
        def sliding(l: Int, r: Int): Unit = if (r>=s.length) return else {
            cnt(s(r)) = cnt.getOrElse(s(r), 0) - 1
            var _l = l
            while (cnt(s(r)) < 0){
                cnt(s(_l)) = cnt(s(_l)) + 1
                _l += 1
            }
            if (r-_l+1 == p.length) 
                ans = _l :: ans
            sliding(_l, r+1)
        }

        sliding(0, 0)
        ans
    }
}

object Solution {
    def frequencySort(s: String): String = {
        val m = s.groupMapReduce(identity)(_=>1)(_+_)
        s.sortWith((c1,c2)=> { if (m(c1)==m(c2)) c1>c2 else m(c1)>m(c2)})
    }
}

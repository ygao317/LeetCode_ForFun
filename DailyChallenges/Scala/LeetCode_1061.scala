object Solution {
    def smallestEquivalentString(s1: String, s2: String, baseStr: String): String = {
        val v = (0 until 26).toArray;

        def find(i: Int): Int = if (v(i) == i) i else {
            v(i) = find(v(i)); v(i)
        }

        for (i <- 0 until s1.length){
            val i1 = find(s1(i) - 'a')
            val i2 = find(s2(i) - 'a')
            if (i1 > i2) v(i1) = i2 else v(i2) = i1
        }

        baseStr.map((ch: Char) => ('a' + find(ch - 'a')).toChar)
    }
}

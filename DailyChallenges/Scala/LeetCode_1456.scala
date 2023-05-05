object Solution {
    def maxVowels(s: String, k: Int): Int = {
        var ans = s.substring(0,k).count("aeiou".contains(_))
        var lc = ans;
        for (i <- k until s.length){
            if ("aeiou".contains(s(i))) lc += 1
            if ("aeiou".contains(s(i-k))) lc -= 1
            ans = lc max ans
            if (ans == k) return k;
        }
        ans
        //s.sliding(k).map(_.count("aeiou".contains(_))).max
    }
}

object Solution {
    def wordPattern(pattern: String, s: String): Boolean = {
        val as = s.split(" ")
        if (pattern.length != as.length) false else {
            val pdl = pattern.distinct.length
            val sdl = as.distinct.length
            val mdl = as.zip(pattern).distinct.length
            pdl == sdl && pdl == mdl
        }
    }
}

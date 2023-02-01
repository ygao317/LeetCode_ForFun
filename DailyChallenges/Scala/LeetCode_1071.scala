object Solution {
    def gcdOfStrings(str1: String, str2: String): String = {
        if (str1 == str2) str1
        else if (str1.length > str2.length) 
            gcdOfStrings(str2, str1)
        else {
            if (str1 == str2.take(str1.length))
                gcdOfStrings(str2.drop(str1.length), str1)
            else
                ""
        }
    }
}

object Solution {
    def compress(chars: Array[Char]): Int = {
        var j = 0; var cnt = 0;
        for (i <- 0 until chars.length){
            if (chars(i) == chars(j)) cnt += 1
            else{
                j += 1
                if (cnt > 1){
                    for (ch <- cnt.toString){
                        chars(j) = ch
                        j += 1
                    }
                }
                chars(j) = chars(i)
                cnt = 1
            }
        }
        if (cnt > 1){
            for (ch <- cnt.toString){
                j += 1
                chars(j) = ch
            }
        }
        j+1
    }
}

object Solution {
    def exist(board: Array[Array[Char]], word: String): Boolean = {
        val dir = Array(1, 0, -1, 0, 1)
        
        def dfs(idx: Int, x: Int, y:Int): Boolean = {
            if (board(x)(y) != word(idx)) return false
            if (idx == word.length-1) return true
            board(x)(y) = '0'
            for (d <- 0 to 3; xn = x + dir(d) if xn>=0 && xn < board.length;
                 yn = y + dir(d+1) if yn>=0 && yn < board(0).length; if dfs(idx+1, xn, yn)) return true
            board(x)(y) = word(idx)
            false
        }
        
        for (i <- 0 until board.length; j<- 0 until board(0).length; if dfs(0,i, j))
            return true
        
        false
    }
}

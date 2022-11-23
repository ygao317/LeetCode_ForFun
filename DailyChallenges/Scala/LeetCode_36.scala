object Solution {
    def isValidSudoku(board: Array[Array[Char]]): Boolean = {
        
        def isValid(chs: Char*): Boolean = {
            val s = collection.mutable.Set.empty[Char]
            for (ch <- chs if ch != '.')
                if (s contains ch) return false else s += ch
            true
        }
        
        // row check
        for (arr <- board)
            if (!isValid(arr:_*)) return false
        
        // col check
        for (arr <- board.transpose)
            if (!isValid(arr:_*)) return false
        
        // sub check
        for (r <- Array(0, 3, 6); c <- Array(0, 3, 6))
            if (!isValid(board(r)(c),board(r)(c+1),board(r)(c+2),
                        board(r+1)(c),board(r+1)(c+1),board(r+1)(c+2),
                        board(r+2)(c),board(r+2)(c+1),board(r+2)(c+2)))
                return false
        
        true
    }
}

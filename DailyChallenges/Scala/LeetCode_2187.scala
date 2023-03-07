object Solution {
    def minimumTime(time: Array[Int], totalTrips: Int): Long = {
        def count(t: Long): Boolean = {
            time.foldLeft(0L)((c, i) => {
                val _c = c + t/i;
                if (_c >= totalTrips) return false;
                _c
            })
            true
        }

        def bs(l: Long, r: Long): Long = if (l >= r) l else {
            val m = l + (r-l)/2
            if (count(m)) bs(m+1, r) else bs(l, m)
        }

        bs(1, 1e14.toLong)
    }
}

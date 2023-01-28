import scala.collection.SortedSet

class SummaryRanges() {
    var memory = SortedSet[Int]()

    def addNum(value: Int) {
        memory += value
    }

    def getIntervals(): Array[Array[Int]] = {
        memory.tail.foldLeft(Array(Array(memory.head, memory.head))) {(acc, x) =>
            if (acc.last(1) + 1 == x) {
                acc.last(1) = x
                acc
            }
            else 
                acc :+ Array(x, x)
        }
    }
}

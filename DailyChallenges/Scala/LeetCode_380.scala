import scala.collection.mutable.{Map, ArrayBuffer}
import scala.util.Random

class RandomizedSet() {
    private val m = Map.empty[Int, Int]
    private val a = ArrayBuffer.empty[Int]

    def insert(`val`: Int): Boolean = m.get(`val`) match {
        case Some(_) => false
        case None => 
            a.append(`val`)
            m += `val` -> (a.length-1)
            true
    }

    def remove(`val`: Int): Boolean = m.get(`val`) match {
        case Some(idx) =>
            a(idx) = a.last
            m(a.last) = m(`val`)
            m.remove(`val`)
            a.remove(a.length-1)
            true
        case None => false
    }

    def getRandom(): Int = {
        a(Random.nextInt(a.length))
    }
}

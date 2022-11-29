def eval(s:String): Int = 
if (s contains '+') s.splitAt(s lastIndexOf '+') match {case (l, r) => eval(l) + eval(r.drop(1))}
else if (s contains '-') s.splitAt(s lastIndexOf '-') match {case (l, r) => eval(l) - eval(r.drop(1))}
else if (s contains '*') s.splitAt(s indexOf '*') match {case (l, r) => eval(l) * eval(r.drop(1))}
else s.toInt

val s = "12-2*8*2"
println(eval(s))

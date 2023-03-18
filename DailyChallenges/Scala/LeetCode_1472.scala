class BrowserHistory(_homepage: String) {
    var fl = List.empty[String] 
    var bl: List[String] = _homepage :: Nil

    def visit(url: String) {
        if (fl.nonEmpty) fl=Nil
        bl = url :: bl    
    }

    def back(steps: Int): String = {
        if (bl.tail == Nil || steps == 0) bl.head
        else{
            fl = bl.head :: fl
            bl = bl.tail
            back(steps - 1)
        }
    }

    def forward(steps: Int): String = {
        if (fl.isEmpty || steps == 0) bl.head
        else{
            bl = fl.head :: bl
            fl = fl.tail
            forward(steps-1)
        }
    }

}

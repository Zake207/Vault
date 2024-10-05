

class Node:
    # Colocar parametros fuera del constructor los trata globales en todas las instancias de la clase
    def __init__(self, data):
        self.data = int(data)
        self.childs = set()
        self.fathers = set()
        
    def __init__(self, data, childs, fathers):
        self.data = int(data)
        self.childs = childs
        self.fathers = fathers

    def __str__(self):
        mystring = f"/// Node: {self.data}\n"
        mystring += "Childs:\n"
        for child in self.childs:
            mystring += f"\t{child[0]} -> {child[1]}\n"
        # mystring += "Fathers:\n"
        # for father in self.fathers:
        #     mystring += f"\t{father[0]} -> {father[1]}\n"
        return mystring

    def GetData(self) -> int:
        return self.data
    
    def GetChilds(self) -> set:
        return self.childs
    
    def GetFathers(self) -> set:
        return self.fathers
    
    def InsertChild(self, node, cost):
        self.childs.add((node, cost))
        
    def InsertFather(self, node, cost):
        self.fathers.add((node, cost))
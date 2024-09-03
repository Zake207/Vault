"""
RESPONSABILIDADES DEL RETÍCULO:
    - Manejar las pocisiones de cada célula
    - Calcular la siguiente generación de células
    - Establecer los estados siguientes de cada célula
"""

import Cell
    
class Lattice:
    
    def __init__(self, rows = 1, columns = 1) -> None:
        print("The Lattice Constructor has been called")
        if rows > 0:
            self.__rows = int(rows)
        if rows > 0:
            self.__columns = int(columns)
        self.__lattice = []
        aux_list = []
        for i in range(-1, rows):
            for j in range(-1, columns):
                aux_cell = Cell.Cell("-", i, j)
                aux_list.append(aux_cell)
            self.__lattice.append(aux_list)
            aux_list = []
            
    def __str__(self) -> str:
        lattice = ""
        for row in range(0,self.__rows + 1):
            for column in range(0,self.__columns + 1):
                lattice += self.__lattice[row][column].GetState() + "     "
            lattice += "\n"
        return lattice
    
    def SetAlive(self, x, y):
        self.__lattice[x][y].SetState("x")
    
    def CalculateNextGeneration(self) -> None:
        living_cells = 0
        
        for x in range(self.__rows + 1):
            if x + 1 > self.__rows:
                x = -1
            for y in range(self.__columns + 1):
                if y + 1 > self.__columns:
                    y = -1
                living_cells = self.__lattice[x - 1][y - 1].IsAlive() + self.__lattice[x - 1][y].IsAlive() + self.__lattice[x - 1][y + 1].IsAlive() + self.__lattice[x][y - 1].IsAlive() + self.__lattice[x][y + 1].IsAlive() + self.__lattice[x + 1][y - 1].IsAlive() + self.__lattice[x + 1][y].IsAlive() + self.__lattice[x + 1][y + 1].IsAlive()
                match self.__lattice[x][y].IsAlive():
                    case 1:
                        if living_cells in range(2,4):
                            self.__lattice[x][y].SetNextState("x")
                        else:
                            self.__lattice[x][y].SetNextState("-")
                    case 0:
                        if living_cells == 3:
                            self.__lattice[x][y].SetNextState("x")
                        else:
                            self.__lattice[x][y].SetNextState("-")
                living_cells = 0
            
                    
    def UpdateGeneration(self) -> None:
        for x in range(self.__rows + 1):
            for y in range(self.__columns + 1):
                self.__lattice[x][y].UpdateState()


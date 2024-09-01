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
        print("Next you'll have to write the coordinates of the cells you want alive at the beginning of the simaltion.")
        print("Type 'q' to break in any moment.")
        coor_x = 0
        coor_y = 0
        while True:
            coor_x = input("Introduce the coordinate X of the cell: ")
            if coor_x == "q" or int(coor_x) not in range(0,self.__rows): 
                break
            coor_y = input("Now the coordiante Y of the cell: ")
            if coor_y == "q" or int(coor_y) not in range(0,self.__columns): 
                break
            self.__lattice[int(coor_x)][int(coor_y)].SetState("x")
            
    def __PrintLattice(self) -> None:
        for row in range(0,self.__rows + 1):
            for column in range(0,self.__columns + 1):
                print(self.__lattice[row][column], end=" ")
            print()
            
    def __str__(self) -> str:
        self.__PrintLattice()
        empty = ""
        return empty
    
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


        
        
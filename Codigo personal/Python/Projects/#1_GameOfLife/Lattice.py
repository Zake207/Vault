"""
RESPONSABILIDADES DEL RETÍCULO:
    - Manejar las pocisiones de cada célula
    - Calcular la siguiente generación de células
    - Establecer los estados siguientes de cada célula
"""

import Cell
    
class Lattice:
    __rows = 0
    __columns = 0
    __lattice = []
    
    def __init__(self, rows = 1, columns = 1) -> None:
        print("The Lattice Constructor has been called")
        if rows > 0:
            self.__rows = int(rows)
        if rows > 0:
            self.__columns = int(columns)
        self.__lattice = []
        aux_list = []
        for i in range(0, rows):
            for j in range(0, columns):
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
            
    def __str__(self) -> str:
        lattice = ""
        for row in range(self.__rows):
            for column in range(self.__columns):
                lattice += self.__lattice[row][column].GetState() + " "
            lattice += "\n"
        return lattice
    
    def SetAlive(self, x, y):
        self.__lattice[x][y].SetState("x")

    def IsAlive(self, cor_x, cor_y) -> int:
        return self.__lattice[cor_x][cor_y].IsAlive()
    
    def CalculateNextGeneration(self) -> None:
        living_cells = 0
        # Calculate the next state of the cell based on the cells around
        for x in range(self.__rows):
            for y in range(self.__columns):
                if x == self.__rows - 1:
                    # x -> limite       y -> limite
                    if y == self.__columns - 1:
                        # print(f"d   ({x}, {y})  {living_cells}")
                        living_cells = self.IsAlive(x-1,y-1) + self.IsAlive(x-1,y) + self.IsAlive(x-1,0) + self.IsAlive(x,y-1) + self.IsAlive(x,0) + self.IsAlive(0,y-1) + self.IsAlive(0,y) + self.IsAlive(0,0)
                    # x -> limite       y -> no limite
                    else:
                        # print(f"c   ({x}, {y})  {living_cells}")
                        living_cells = self.IsAlive(x-1,y-1) + self.IsAlive(x-1,y) + self.IsAlive(x-1,y+1) + self.IsAlive(x,y-1) + self.IsAlive(x,y+1) + self.IsAlive(0,y-1) + self.IsAlive(0,y) + self.IsAlive(0,y+1)
                else:
                    # x -> no limite       y -> limite
                    if y == self.__columns - 1:
                        # print(f"b   ({x}, {y})  {living_cells}")
                        living_cells = self.IsAlive(x-1,y-1) + self.IsAlive(x-1,y) + self.IsAlive(x-1,0) + self.IsAlive(x,y-1) + self.IsAlive(x,0) + self.IsAlive(x+1,y-1) + self.IsAlive(x+1,y) + self.IsAlive(x+1,0)
                    # x -> no limite       y -> no limite
                    else:
                        # print(f"a   ({x}, {y})  {living_cells}")
                        living_cells = self.IsAlive(x-1,y-1) + self.IsAlive(x-1,y) + self.IsAlive(x-1,y+1) + self.IsAlive(x,y-1) + self.IsAlive(x,y+1) + self.IsAlive(x+1,y-1) + self.IsAlive(x+1,y) + self.IsAlive(x+1,y+1)
                # Decide the next state the cell
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
        for x in range(self.__rows):
            for y in range(self.__columns):
                self.__lattice[x][y].UpdateState()


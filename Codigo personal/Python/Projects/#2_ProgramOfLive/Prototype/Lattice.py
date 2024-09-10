"""
RESPONSABILIDADES DE LA CÉLULA:
    - Administrar su estado
    - Conocer su pocisión
"""

class Cell :
    #   /// ATRIBUTES
    __coordinate_x = 0
    __coordinate_y = 0
    __actual_state = "-"
    __next_state = "-"

    #   /// METHODS
    # CONSTRUCTOR
    def __init__(self, state = "-", coordinate_x = 0, coordinate_y = 0) -> None:
        # Comprobar si el estado es válido
        if state in "-x":
            self.__actual_state = state
        else:
            print(f" /// El estado de la célula con coordenadas ({coordinate_x},{coordinate_y}) es inválida")
        # Establecer las coordenadas
        if coordinate_x >= 0:
            self.__coordinate_x = int(coordinate_x)
        if coordinate_y >= 0:
            self.__coordinate_y = int(coordinate_y)
        self.__next_state = "-"
    
    def __str__(self) -> str:
        return (f"{self.__actual_state}")
        
    # GETTERS
    def GetState(self) -> str:
        return self.__actual_state
    
    def IsAlive(self) -> int:
        if self.GetState() == "x":
            return 1
        return 0
    
    def GetCoordinateX(self) -> int:
        return self.__coordinate_x
    
    def GetCoordinateY(self) -> int:
        return self.__coordinate_y
        
    # SETTERS
    def SetState(self, state = "-") -> None:
        if state in "-x":
            self.__actual_state = state

    def SetNextState(self, future_state = "-") -> None:
        if future_state in "-x":
            self.__next_state = future_state
    
    def SetCoordinates(self, coor_x, coor_y) -> None:
        if coor_x >= 0:
            self.__coordinate_x = int(coor_x)
        if coor_y >= 0:
            self.__coordinate_y = int(coor_y)
            
    def UpdateState(self) -> None:
        self.__actual_state = self.__next_state
        self.__next_state = "-"
"""
RESPONSABILIDADES DEL RETÍCULO:
    - Manejar las pocisiones de cada célula
    - Calcular la siguiente generación de células
    - Establecer los estados siguientes de cada célula
"""

class Lattice:
    #   /// ATRIBUTES
    __rows = 0
    __columns = 0
    __lattice = []
    
    #   /// METHODS
    def __init__(self, rows = 1, columns = 1) -> None:
        if rows > 0:
            self.__rows = int(rows)
        if rows > 0:
            self.__columns = int(columns)
        self.__lattice = []
        aux_list = []
        for i in range(0, rows):
            for j in range(0, columns):
                aux_cell = Cell("-", i, j)
                aux_list.append(aux_cell)
            self.__lattice.append(aux_list)
            aux_list = []
            
    def __str__(self) -> str:
        lattice = ""
        for row in range(self.__rows):
            for column in range(self.__columns):
                lattice += self.__lattice[row][column].GetState() + "   "
            lattice += "\n"
        return lattice
    
    def SwitchState(self, x, y):
        if self.__lattice[x][y].GetState() == "-":
            self.__lattice[x][y].SetState("x")
        else:
            self.__lattice[x][y].SetState("-")

    def IsAlive(self, cor_x, cor_y) -> int:
        return self.__lattice[cor_x][cor_y].IsAlive()
    
    def Clear(self) -> None:
        for x in range(self.__rows):
            for y in range(self.__columns):
                self.__lattice[x][y].SetState("-")

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


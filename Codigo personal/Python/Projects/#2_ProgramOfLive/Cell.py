"""
RESPONSABILIDADES DE LA CÉLULA:
    - Administrar su estado
    - Conocer su pocisión
"""

from typing import Any


class Cell :
    
    # CONSTRUCTOR DE LA CLASE
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
        

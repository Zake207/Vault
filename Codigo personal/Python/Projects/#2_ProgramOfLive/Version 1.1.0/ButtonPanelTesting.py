import tkinter

window = tkinter.Tk()
window.title("Game Of Life: Setting the starting cell")
window.geometry("760x520")
window.iconbitmap("cell.ico")
window.resizable(0,0)
window.config(bg = "lightblue", cursor = "tcross")

class MatrixButton:
    __button = tkinter.Button(window, width = 4)
    __coor_x = 1
    __coor_y = 1

    def __init__(self, x = 0, y = 0) -> None:
        self.__coor_x = x
        self.__coor_y = y
        self.__button.config(text = f"{self.__coor_x}-{self.__coor_y}", command = self.Activate)
        self.__button.grid(row = self.__coor_x, column = self.__coor_y)

    def GetX(self) -> int:
        return self.__coor_x
    
    def GetY(self) -> int:
        return self.__coor_y
    
    def Activate(self) -> None:
        print(f"{self.__coor_x}-{self.__coor_y}")
    
buttons = []
for i in range(20):
    aux_list = []
    for j in range(20):
        aux_button = MatrixButton(i, j)
        aux_list.append(aux_button)
    buttons.append(aux_list)
    aux_list = []

for i in buttons:
    for j in i:
        print(type(j))

window.mainloop()
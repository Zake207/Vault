import Lattice
import tkinter
import tkinter.messagebox

###                                                         /// GLOBAL VARIABLES ///
gen_number = 0
main_lattice = Lattice.Lattice(20, 20)
instructions_of_the_game = open("instrucciones.txt").read()
button_list = list()
        
# /// TKINTER WINDOWS
window = tkinter.Tk()

###                                                         /// FUNCTIONS ///
def DisplayInfo() -> None:
    tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")

def Configuration() -> None:
    # tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")
    config_window = tkinter.Tk()
    config_window.title("Configuration")
    config_window.geometry("750x650")
    config_window.config(bg = "lightblue", cursor = "tcross")
    ButtonCreator(config_window,button_list)
    config_window.mainloop()
    

def NextGen() -> None:
    global gen_number
    if gen_number != 0:
        main_lattice.CalculateNextGeneration()
        main_lattice.UpdateGeneration()
    gen_number += 1
    gen_label.config(text = f"\nGENERATION: {gen_number}")
    matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")

def ClearLattice() -> None:
    main_lattice.Clear()
    matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")

def SubmitPosition(x, y) -> None:
    main_lattice.SwitchState(x, y)
    matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")

def ButtonCreator(window, button_list) :
    button_list = []
    for i in range(20):
        for j in range(20):
            aux_button = MatrixButton(i,j, window)
            button_list.append(aux_button)



###                                                         /// TKINTER ELEMENTS ///
# /// LABELS
matrix_label = tkinter.Label(window, text = f"INSTRUCTIONS\n\n{instructions_of_the_game}", bg = "lightblue", font = ("courier", 10, "bold"), justify = "left")
gen_label = tkinter.Label(window, bg = "lightblue", text = f"\nGENERATION: {gen_number}\n\n", font = ("courier", 14, "bold"))
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///", relief = "solid", font = ("courier", 14, "bold"), bg ="lightblue")

# /// BUTTONS
button_clear_lattice = tkinter.Button(window, text = "Clear", fg = "orange", bg = "lightgrey", width = 7, command = ClearLattice)
button_configuration = tkinter.Button(window, text = "Configuration", fg = "blue", bg = "lightgrey", command = Configuration)
button_help = tkinter.Button(window, text = "Help", fg = "red", bg = "lightgrey", command = DisplayInfo)
button_next_gen = tkinter.Button(window, text = "Next Gen", fg = "green", bg = "lightgrey", command = NextGen)

###                                                         /// CLASSES ///
class MatrixButton:
    __coor_x = 0
    __coor_y = 0
    __button_func = 0
    __button = 0
    
    def __init__(self, x, y, window) -> None:
        self.__coor_x = x
        self.__coor_y = y
        self.__button_func = lambda: SubmitPosition(self.__coor_x, self.__coor_y)
        self.__button = tkinter.Button(window, text = f"{self.__coor_x}-{self.__coor_y}", width = 1, height = 1, command = self.__button_func)
        self.__button.grid(row = x, column = y)  
        pass
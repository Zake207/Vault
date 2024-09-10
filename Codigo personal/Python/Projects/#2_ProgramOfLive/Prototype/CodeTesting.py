import Lattice
import tkinter
import tkinter.messagebox


def DisplayInfo() -> None:
    tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")


number_of_rows = 20
number_of_columns = 20
gen_number = 0
main_lattice = Lattice.Lattice(number_of_rows, number_of_columns)
def NextGen() -> None:
    global gen_number
    # Actualizar la matriz
    if gen_number != 0:
        main_lattice.CalculateNextGeneration()
        main_lattice.UpdateGeneration()
    # Actualizar el numero de generación
    gen_number += 1
    gen_label.config(text = f"\nGENERATION: {gen_number}")
    matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")

def Configuration() -> None:
    tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")


def ClearLattice() -> None:
    main_lattice.Clear()
    matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")



# Game configuration window
initial_window = tkinter.Tk()
initial_window.title("Game Of Life: Setting the starting cell")
initial_window.geometry("250x250")
initial_window.iconbitmap("cell.ico")
initial_window.resizable(0,0)
initial_window.config(bg = "lightblue", cursor = "tcross")

stored_initial_pos_x = tkinter.StringVar()
stored_initial_pos_y = tkinter.StringVar()

def SubmitPosition() -> None:
    initial_pos_x = stored_initial_pos_x.get()
    initial_pos_y = stored_initial_pos_y.get()

    if (int(initial_pos_x) not in range(20)) or (int(initial_pos_y) not in range(20)):
        tkinter.messagebox.showerror(title = "/// ERROR", message = "You submitted the wrong coordinates.\nThey must be between 0 and 19.")
    else:
        main_lattice.SwitchState(int(initial_pos_x), int(initial_pos_y))
        matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")
    stored_initial_pos_x.set("")
    stored_initial_pos_y.set("")

pos_x_entry_label = tkinter.Label(initial_window, text = "Coordinate X:", bg = "lightblue").pack()
pos_x_entry = tkinter.Entry(initial_window, textvariable = stored_initial_pos_x).pack()
pos_y_entry_label = tkinter.Label(initial_window, text = "Coordinate Y:", bg = "lightblue").pack()
pos_y_entry = tkinter.Entry(initial_window, textvariable = stored_initial_pos_y).pack()

submit_coordinates_button = tkinter.Button(initial_window, command = SubmitPosition, text = "Submit", bg = "lightgrey", width = 7).pack()


# /// Window Configuration
window = tkinter.Tk()
window.title("Game Of Life")
window.geometry("1000x650") # -> Stablish the size of the window
window.iconbitmap("cell.ico")
window.resizable(0,0) # -> Block the user to change the dimensions of the window
window.configure(bg = "lightblue", cursor = "tcross")


# /// Labels
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///", relief = "solid", font = ("courier", 14, "bold"), bg ="lightblue").pack()

gen_label = tkinter.Label(window, bg = "lightblue", text = f"\nGENERATION: {gen_number}\n\n", font = ("courier", 14, "bold"))
gen_label.pack()

instructions_of_the_game = open("instrucciones.txt").read()
matrix_label = tkinter.Label(window, text = f"INSTRUCTIONS\n\n{instructions_of_the_game}", bg = "lightblue", font = ("courier", 10, "bold"), justify = "left")
matrix_label.pack()


# /// Buttons
button_next_gen = tkinter.Button(window, text = "Next Gen", fg = "green", bg = "lightgrey", command = NextGen)
button_next_gen.pack()
button_next_gen.place(x=900, y=50)

button_help = tkinter.Button(window, text = "Help", fg = "red", bg = "lightgrey", command = DisplayInfo)
button_help.pack()
button_help.place(x=950, y=612)

button_configuration = tkinter.Button(window, text = "Configuration", fg = "blue", bg = "lightgrey", command = Configuration)
button_configuration.pack()
button_configuration.place(x=50, y=50)

button_clear_lattice = tkinter.Button(initial_window, text = "Clear", bg = "lightgrey", width = 7, command = ClearLattice)
button_clear_lattice.pack()

window.mainloop()
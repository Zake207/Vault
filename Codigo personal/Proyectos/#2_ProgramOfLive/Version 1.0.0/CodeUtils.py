import Lattice
import tkinter
import tkinter.messagebox

###                                                         /// GLOBAL VARIABLES ///
gen_number = 0
main_lattice = Lattice.Lattice(20, 20)
instructions_of_the_game = open("instrucciones.txt").read()
# /// TKINTER WINDOWS
window = tkinter.Tk()
initial_window = tkinter.Tk()
# /// ENTRY VARIABLES
stored_initial_pos_x = tkinter.StringVar(initial_window,"","sip-x")
stored_initial_pos_y = tkinter.StringVar(initial_window,"","sip-y")

###                                                         /// FUNCTIONS ///
def DisplayInfo() -> None:
    tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")

def Configuration() -> None:
    tkinter.messagebox.showerror(title = "/// ERROR", message = "This option is not implemented")

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

def SubmitPosition() -> None:
    initial_pos_x = int(stored_initial_pos_x.get())
    initial_pos_y = int(stored_initial_pos_y.get())
    if (initial_pos_x not in range(20)) or (initial_pos_y not in range(20)):
        tkinter.messagebox.showerror(title = "/// ERROR", message = "You submitted the wrong coordinates.\nThey must be between 0 and 19.")
    else:
        main_lattice.SwitchState(initial_pos_x, initial_pos_y)
        matrix_label.config(text = main_lattice, font = ("Arial", 15, "bold"), justify = "center")
    stored_initial_pos_x.set("")
    stored_initial_pos_y.set("")

###                                                         /// TKINTER ELEMENTS ///
# /// LABELS
matrix_label = tkinter.Label(window, text = f"INSTRUCTIONS\n\n{instructions_of_the_game}", bg = "lightblue", font = ("courier", 10, "bold"), justify = "left")
gen_label = tkinter.Label(window, bg = "lightblue", text = f"\nGENERATION: {gen_number}\n\n", font = ("courier", 14, "bold"))
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///", relief = "solid", font = ("courier", 14, "bold"), bg ="lightblue")
pos_x_entry_label = tkinter.Label(initial_window, text = "Coordinate X:", bg = "lightblue")
pos_y_entry_label = tkinter.Label(initial_window, text = "Coordinate Y:", bg = "lightblue")

# /// ENTRY
pos_x_entry = tkinter.Entry(initial_window)
pos_x_entry.config(textvariable = stored_initial_pos_x)
pos_y_entry = tkinter.Entry(initial_window)
pos_y_entry.config(textvariable = stored_initial_pos_y)

# /// BUTTONS
submit_coordinates_button = tkinter.Button(initial_window, command = SubmitPosition, text = "Submit", bg = "lightgrey", width = 7)
button_clear_lattice = tkinter.Button(initial_window, text = "Clear", bg = "lightgrey", width = 7, command = ClearLattice)
button_configuration = tkinter.Button(window, text = "Configuration", fg = "blue", bg = "lightgrey", command = Configuration)
button_help = tkinter.Button(window, text = "Help", fg = "red", bg = "lightgrey", command = DisplayInfo)
button_next_gen = tkinter.Button(window, text = "Next Gen", fg = "green", bg = "lightgrey", command = NextGen)
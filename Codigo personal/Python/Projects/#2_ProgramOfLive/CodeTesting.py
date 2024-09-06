import Lattice
import tkinter
import tkinter.messagebox

###############################################################################################################################################
def DisplayInfo() -> None:
    pass
###############################################################################################################################################
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
###############################################################################################################################################
def Configuration() -> None:
    pass
###############################################################################################################################################
###############################################################################################################################################


# Game configuration
initial_window = tkinter.Tk()
initial_window.title("Game Of Life: Setting the starting cell")
initial_window.geometry("250x250")
initial_window.resizable(0,0)
initial_window.config(bg = "lightblue", cursor = "tcross")

stored_initial_pos_x = tkinter.StringVar()
stored_initial_pos_y = tkinter.StringVar()

def SubmitPosition() -> None:
    initial_pos_x = stored_initial_pos_x.get()
    initial_pos_y = stored_initial_pos_y.get()

    if (int(initial_pos_x) not in range(0,21)) or (int(initial_pos_y) not in range(0,21)):
        tkinter.messagebox.showerror(title = "/// ERROR", message = "You submitted the wrong coordinates.\nThey must be between 0 and 20.")
    else:
        main_lattice.SetAlive(int(initial_pos_x), int(initial_pos_y))
    stored_initial_pos_x.set("")
    stored_initial_pos_y.set("")

pos_x_entry_label = tkinter.Label(initial_window, text = "Coordinate X:", bg = "lightblue").pack()
pos_x_entry = tkinter.Entry(initial_window, textvariable = stored_initial_pos_x).pack()
pos_y_entry_label = tkinter.Label(initial_window, text = "Coordinate Y:", bg = "lightblue").pack()
pos_y_entry = tkinter.Entry(initial_window, textvariable = stored_initial_pos_y).pack()

submit_coordinates_button = tkinter.Button(initial_window, command = SubmitPosition, text = "Submit").pack()

###############################################################################################################################################
###############################################################################################################################################

# /// Window Configuration
window = tkinter.Tk()
window.title("Game Of Life")
window.geometry("1000x650") # -> Stablish the size of the window
window.resizable(0,0) # -> Block the user to change the dimensions of the window
window.configure(bg = "lightblue", cursor = "tcross")
###############################################################################################################################################

# /// Labels
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///", relief = "solid", font = ("courier", 14, "bold"), bg ="lightblue").pack()

gen_label = tkinter.Label(window, bg = "lightblue", text = f"\nGENERATION: {gen_number}\n\n", font = ("courier", 14, "bold"))
gen_label.pack()

instructions_of_the_game = open("instrucciones.txt").read()
matrix_label = tkinter.Label(window, text = f"INSTRUCTIONS\n\n{instructions_of_the_game}", bg = "lightblue", font = ("courier", 10, "bold"), justify = "left")
matrix_label.pack()
###############################################################################################################################################

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

window.mainloop()










# # Función para reemplazar el contenido
# def reemplazar_contenido():
#     # Almacena los widgets actuales
#     global widgets_anteriores
#     widgets_anteriores = root.winfo_children()

#     # Oculta los widgets actuales en lugar de destruirlos
#     for widget in widgets_anteriores:
#         widget.pack_forget()

#     # Agrega nuevos widgets
#     nuevo_label = tk.Label(root, text="Este es el nuevo contenido")
#     nuevo_label.pack(padx=20, pady=20)

#     boton_volver = tk.Button(root, text="Volver", command=restaurar_contenido)
#     boton_volver.pack(padx=20, pady=20)

# # Función para restaurar el contenido anterior
# def restaurar_contenido():
#     # Oculta los widgets actuales
#     for widget in root.winfo_children():
#         widget.pack_forget()

#     # Vuelve a mostrar los widgets anteriores
#     for widget in widgets_anteriores:
#         widget.pack()

# # Crear la ventana principal
# root = tk.Tk()
# root.title("Ventana Principal")

# # Crear el contenido original
# label_original = tk.Label(root, text="Contenido original de la ventana")
# label_original.pack(padx=20, pady=20)

# btn_reemplazar = tk.Button(root, text="Reemplazar Contenido", command=reemplazar_contenido)
# btn_reemplazar.pack(padx=20, pady=20)

# # Iniciar el bucle principal
# root.mainloop()
import tkinter

def DisplayInfo() -> None:
    pass

def NextGen() -> None:
    pass
    
def Configuration() -> None:
    pass






# /// Window Configuration
window = tkinter.Tk()
window.title("Game Of Life")
window.geometry("1000x650")
window.resizable(0,0) # -> Poder cambiar el tamaño de la ventana
# /// Header
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///").pack()
# /// Next Gen Button
button_next_gen = tkinter.Button(window, text = "Next Gen", fg = "green", bg = "grey", command = NextGen)
button_next_gen.pack()
button_next_gen.place(x=600, y=50)
# /// Help Button
button_help = tkinter.Button(window, text = "Help", fg = "red", bg = "grey", command = DisplayInfo)
button_help.pack()
button_help.place(x=675, y=550)
# /// Configurate Button
button_configuration = tkinter.Button(window, text = "Configuration", fg = "blue", bg = "grey", command = Configuration)
button_configuration.pack()
button_configuration.place(x=50, y=50)

window.mainloop()
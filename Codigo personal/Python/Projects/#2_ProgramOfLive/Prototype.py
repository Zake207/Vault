import tkinter
import tkinter.messagebox

def DisplayInfo() -> None:
    tkinter.messagebox.showinfo("Additional info", "If you have any problem or questions about this app click the link below:")
    pass

def NextGen() -> None:
    pass
    
def Configuration() -> None:
    pass






# /// Window Configuration
window = tkinter.Tk()
window.title("Game Of Life")
window.geometry("1000x650")
window.resizable(0,0) # -> Block the user to change the dimensions of the window
window.configure(bg = "lightblue", cursor = "tcross")
# /// Header
header = tkinter.Label(window, text = "///  GAME OF LIFE  ///", relief = "solid").pack()
# /// Next Gen Button
button_next_gen = tkinter.Button(window, text = "Next Gen", fg = "green", bg = "lightgrey", command = NextGen)
button_next_gen.pack()
button_next_gen.place(x=900, y=50)
# /// Help Button
button_help = tkinter.Button(window, text = "Help", fg = "red", bg = "lightgrey", command = DisplayInfo)
button_help.pack()
button_help.place(x=950, y=612)
# /// Configurate Button
button_configuration = tkinter.Button(window, text = "Configuration", fg = "blue", bg = "lightgrey", command = Configuration)
button_configuration.pack()
button_configuration.place(x=50, y=50)

window.mainloop()
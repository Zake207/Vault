import CodeUtils as Utils
#                                               /// Main Window Configuration ///
Utils.window.title("Game Of Life")
Utils.window.geometry("1000x650")
# Utils.window.iconbitmap("cell.ico")       #   NO FUNCIONA EN UBUNTU
Utils.window.resizable(0,0)
Utils.window.configure(bg = "lightblue", cursor = "tcross")

Utils.button_next_gen.pack()
Utils.button_next_gen.place(x=900, y=50)

Utils.button_help.pack()
Utils.button_help.place(x=950, y=612)

Utils.button_configuration.pack()
Utils.button_configuration.place(x=50, y=50)

Utils.button_clear_lattice.pack()
Utils.button_clear_lattice.place(x=50, y=612)

Utils.header.pack()
Utils.gen_label.pack()
Utils.matrix_label.pack()

Utils.window.mainloop()
Utils.initial_window.mainloop()
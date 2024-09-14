import CodeUtils as Utils

#                                           /// Cell-controler Window Configuration ///
Utils.initial_window.title("Game Of Life: Setting the starting cell")
Utils.initial_window.geometry("250x150")
Utils.initial_window.iconbitmap("cell.ico")
Utils.initial_window.resizable(0,0)
Utils.initial_window.config(bg = "lightblue", cursor = "tcross")

Utils.pos_x_entry_label.grid(row = 0, column = 0)
Utils.pos_x_entry.grid(row = 0, column = 1)
Utils.pos_y_entry_label.grid(row = 1, column = 0)
Utils.pos_y_entry.grid(row = 1, column = 1)

Utils.submit_coordinates_button.grid(row = 2, column = 1)
Utils.button_clear_lattice.grid(row = 2, column = 0)

#                                               /// Main Window Configuration ///
Utils.window.title("Game Of Life")
Utils.window.geometry("1000x650")
Utils.window.iconbitmap("cell.ico")
Utils.window.resizable(0,0)
Utils.window.configure(bg = "lightblue", cursor = "tcross")


Utils.button_next_gen.pack()
Utils.button_next_gen.place(x=900, y=50)

Utils.button_help.pack()
Utils.button_help.place(x=950, y=612)

Utils.button_configuration.pack()
Utils.button_configuration.place(x=50, y=50)

Utils.header.pack()
Utils.gen_label.pack()
Utils.matrix_label.pack()

Utils.window.mainloop()
Utils.initial_window.mainloop()
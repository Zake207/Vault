import tkinter as tk

# Función para reemplazar el contenido
def reemplazar_contenido():
    # Almacena los widgets actuales
    global widgets_anteriores
    widgets_anteriores = root.winfo_children()

    # Oculta los widgets actuales en lugar de destruirlos
    for widget in widgets_anteriores:
        widget.pack_forget()

    # Agrega nuevos widgets
    nuevo_label = tk.Label(root, text="Este es el nuevo contenido")
    nuevo_label.pack(padx=20, pady=20)

    boton_volver = tk.Button(root, text="Volver", command=restaurar_contenido)
    boton_volver.pack(padx=20, pady=20)

# Función para restaurar el contenido anterior
def restaurar_contenido():
    # Oculta los widgets actuales
    for widget in root.winfo_children():
        widget.pack_forget()

    # Vuelve a mostrar los widgets anteriores
    for widget in widgets_anteriores:
        widget.pack()

# Crear la ventana principal
root = tk.Tk()
root.title("Ventana Principal")

# Crear el contenido original
label_original = tk.Label(root, text="Contenido original de la ventana")
label_original.pack(padx=20, pady=20)

btn_reemplazar = tk.Button(root, text="Reemplazar Contenido", command=reemplazar_contenido)
btn_reemplazar.pack(padx=20, pady=20)

# Iniciar el bucle principal
root.mainloop()
"""
REGLAS A SEGUIR: 
    - Nace -> Si hay 3 celulas vivas a su alrededor
    - Vive -> Si hay 2 o 3 células vivas a su alrededor
    - Muere -> Si hay tiene mas de 3 o menos de dos células vivas a su alrededor
    
    - Una celula viva se representa con 'x' y una muerta con '-'
    
    - La frontera funciona devolviendo la célula del extremo opuesto,
      es decir, si al comprobar pocisiones se sale por la derecha comprueba la
      célula de extremo opuesto.
"""

import Lattice
from os import system

system("clr")
print("////////////////////////////////////////////////////////     JUEGO DE LA VIDA     ////////////////////////////////////////////////////////")
print("//// Write the size of the lattice")
rows = 0
columns = 0
while rows < 1:
  rows = int(input("//// Rows: "))
  if rows < 1:
    print("The number introduced is not valid, must be at lest 1")
while columns < 1:
  columns = int(input("//// Columns: "))
  if columns < 1:
    print("The number introduced is not valid, must be at lest 1")
    
main_lattice = Lattice.Lattice(rows, columns)
system("clr")
option = 0
while True:
  print("////////////////////////////////////////////////////////     JUEGO DE LA VIDA     ////////////////////////////////////////////////////////")
  print(main_lattice, end = "\n\n")
  print("1. Show the next generation.")
  print("2. End program.")
  option = int(input("Select one option: "))
  if option == 1:
    main_lattice.CalculateNextGeneration()
    main_lattice.UpdateGeneration()
  elif option == 2:
    break
  system("clr")


import Cell as CellFile
import Lattice as LatticeFile


try:
    print("/// PRUEBAS DE CÓDIGO ///")
    # mycell = CellFile.Cell("-", 5, 3)

    # print("     /// GETTERS ///")
    # print(mycell.GetState())
    # print(mycell.GetCoordinates())
    # print(f"{mycell}")
    
    # print("     /// SETTERS ///")
    # mycell.SetState("x")
    # mycell.SetNextState("x")
    # mycell.SetCoordinates(80,90)
    
    # print(mycell.GetState())
    # print(mycell.GetCoordinates())
    
    # print ("        /// UPDATE ///")
    
    # mycell.UpdateState()
    # print(mycell)
    # mycell.UpdateState()
    # print(mycell)
    
    ##############################################################################################################################################
    ##############################################################################################################################################
    
    # mylattice = LatticeFile.Lattice(20,20)
    # print(mylattice)
    
    # mylattice.SetAlive(0,0)
    # mylattice.SetAlive(1,0)
    # mylattice.SetAlive(1,1)
    # mylattice.SetAlive(2,1)
    
    # mylattice.SetAlive(5,5)
    # mylattice.SetAlive(6,5)
    # mylattice.SetAlive(7,5)
    # mylattice.SetAlive(7,6)
    # mylattice.SetAlive(6,7)
    
    # print(mylattice)
    
    # mylattice.CalculateNextGeneration()
    # mylattice.UpdateGeneration()
    # print(mylattice)
    # mylattice.CalculateNextGeneration()
    # mylattice.UpdateGeneration()
    # print(mylattice)
    # mylattice.CalculateNextGeneration()
    # mylattice.UpdateGeneration()
    # print(mylattice)
    # mylattice.CalculateNextGeneration()
    # mylattice.UpdateGeneration()
    # print(mylattice)
    
    
except Exception as except_name:
    print(f"//////////////////////////////////////////////////////////\n///   EL PROGRAMA ACABA DE SUFRIR EL SIGUIENTE FALLO   ///\n\n{except_name}\n\n//////////////////////////////////////////////////////////")


#include <iostream>
#include <vector>
#include <stdarg.h>

#include "lib/PositionDim.h"
#include "lib/Cell.h"
#include "lib/CellACE.h"
#include "lib/CellLife.h"
#include "lib/FactoryCell.h"
#include "lib/Lattice.h"
#include "lib/Lattice1D.h"
#include "lib/Lattice2D.h"

int main() {
    PositionDim<1, int> pos(1, 4);
    State alive(1);
    // CellLife51_346 c(poss, alive);
    // std::cout << c;
    
    
    // Cell* cell = factory.createCell(pos, alive);
    // std::cout << *cell;
    std::string file{"files/start.txt"};
    FactoryCell* f = new FactoryCellLife23_3;
    Lattice* lattice = new Lattice2DOpen(10, 10,  *f, 1); 
    // FactoryCellAce110 factory;
    // std::string f{"files/start.txt"};
    // Lattice2DOpen lattice(f, factory, 1);
    // lattice[pos].SetState(alive);
    
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;
    lattice->nextGeneration();
    std::cout << *lattice;


    // FactoryCellAce110 factory;
    // Lattice1DOpen lattice(10, factory, 1);
    // lattice[pos].SetState(alive);
    
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();

    // FactoryCellAce110 factory;
    // Lattice1DReflective lattice(10, factory);
    // lattice[pos].SetState(alive);
    
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();

    // FactoryCellAce110 factory;
    // Lattice1DReflective lattice(5, factory);
    // lattice[pos].SetState(alive);
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;

    // FactoryCellLife23_3 factory;
    // Lattice2DPeriodic lattice(5, 5, factory);
    // PositionDim<2,int> pos1(2, 0,0);
    // PositionDim<2,int> pos2(2, 0,4);
    // PositionDim<2,int> pos3(2, 1,1);
    // PositionDim<2,int> pos4(2, 4,4);
    // PositionDim<2,int> pos5(2, 0,1);
    // PositionDim<2,int> pos6(2, 2,2);
    // PositionDim<2,int> pos7(2, 2,3);
    // PositionDim<2,int> pos8(2, 2,4);

    // lattice[pos1].SetState(alive);
    // lattice[pos2].SetState(alive);
    // lattice[pos3].SetState(alive);
    // lattice[pos4].SetState(alive);
    // lattice[pos5].SetState(alive);
    // lattice[pos6].SetState(alive);
    // lattice[pos7].SetState(alive);
    // lattice[pos8].SetState(alive);

    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;



    // PositionDim<> poss(2, 1,5);
    // FactoryCellLife23_3 factory;
    // Lattice2DOpen lattice(5, 5, factory, 1);

 
    // PositionDim<2,int> pos3(2, 1,1);
    // PositionDim<2,int> pos4(2, 4,4);

    // PositionDim<2,int> pos6(2, 2,2);
    // PositionDim<2,int> pos7(2, 2,3);
    // PositionDim<2,int> pos8(2, 2,4);


    // lattice[pos3].SetState(alive);
    // lattice[pos4].SetState(alive);

    // lattice[pos6].SetState(alive);
    // lattice[pos7].SetState(alive);
    // lattice[pos8].SetState(alive);

    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;


//    FactoryCellLife23_3 factory;
//     Lattice2DReflected lattice(5, 5, factory);
//     PositionDim<2,int> pos1(2, 0,0);
//     PositionDim<2,int> pos2(2, 0,4);
//     PositionDim<2,int> pos3(2, 1,1);
//     PositionDim<2,int> pos4(2, 4,4);
//     PositionDim<2,int> pos5(2, 0,1);
//     PositionDim<2,int> pos6(2, 2,2);
//     PositionDim<2,int> pos7(2, 2,3);
//     PositionDim<2,int> pos8(2, 2,4);

//     lattice[pos1].SetState(alive);
//     lattice[pos2].SetState(alive);
//     lattice[pos3].SetState(alive);
//     lattice[pos4].SetState(alive);
//     lattice[pos5].SetState(alive);
//     lattice[pos6].SetState(alive);
//     lattice[pos7].SetState(alive);
//     lattice[pos8].SetState(alive);

//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;
//     lattice.nextGeneration();
//     std::cout << lattice;






//    FactoryCellLife23_3 factory;
//     Lattice2DNoBorder lattice(5, 5, factory);
//     PositionDim<2,int> pos1(2, 0,1);
//     PositionDim<2,int> pos2(2, 1,0);
//     PositionDim<2,int> pos3(2, 1,1);
//     PositionDim<2,int> pos4(2, 2,0);
//     PositionDim<2,int> pos5(2, 2,2);
//     PositionDim<2,int> pos6(2, 3,4);
//     PositionDim<2,int> pos7(2, 4,4);
//     PositionDim<2,int> pos8(2, 4,3);

//     lattice[pos1].SetState(alive);
//     lattice[pos2].SetState(alive);
//     lattice[pos3].SetState(alive);
//     lattice[pos4].SetState(alive);
//     lattice[pos5].SetState(alive);
//     lattice[pos6].SetState(alive);
//     lattice[pos7].SetState(alive);
//     lattice[pos8].SetState(alive);

    // std::cout << lattice;
    // lattice.AddUpperRow();
    // lattice.AddUpperRow();
    // lattice.AddLowerRow();
    // lattice.AddLowerRow();
    // lattice.AddLeftColum();
    // lattice.AddLeftColum();
    // lattice.AddRightColum();
    // lattice.AddRightColum();
    // std::cout << lattice;

    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;
    // lattice.nextGeneration();
    // std::cout << lattice;


    return 0;
}
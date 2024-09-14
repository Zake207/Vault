#include <iostream>
#include <vector>
#include <fstream>

#include "../lib/Lattice.h"
#include "../lib/Cell.h"

int main() {
    std::cout << "###################################################################" << std::endl;
    std::cout << "                        JUEGO DE LA VIDA                           " << std::endl;
    std::cout << "###################################################################" << std::endl;
    State alive(1);
    // CellVector v(10, 0, 0);
    // std::cout << v;
    // for (int i = v.GetInitial(); i < v.GetSize(); ++i) {
    //     v[i].SetState(alive);
    // }
    // v.Push_back();
    // v.Push_front();
    // v.Push_front();
    // v.Push_front();
    // v.Push_back();
    // v.Push_front();
    // v.Push_back();
    // v.Push_back();
    // std::cout << v.GetSize() << " " << v.GetInitial() << std::endl;
    // std::cout << v;
    // v[-7].SetState(alive);
    // v[15].SetState(alive);
    // std::cout << v << std::endl;

    // CellMatrix matrix(10, 10);
    // std::cout << matrix;
    // std::cout << matrix.GetRows() << " " << matrix.GetColums() << " " << std::endl;
    // std::cout << matrix.GetInitialRow() << " " << matrix.GetInitialColum() << " " << std::endl;

    // std::cout << "Filas: " << matrix.GetRows() << " Columnas: " << matrix.GetColums() << std::endl; 
    // for (int i = 0; i < matrix.GetRows(); ++i) {
    //     for (int j = 0; j < matrix[i].GetSize(); ++j) {
    //         matrix[i][j].SetState(alive);
    //     }
    // }
    // std::cout << matrix;
    // matrix.AddLowerRow();
    // matrix.AddUpperRow();
    // matrix.AddLeftColum();
    // matrix.AddRightColum();
    // matrix.AddLowerRow();
    // matrix.AddUpperRow();
    // matrix.AddLeftColum();
    // matrix.AddRightColum();
    // matrix.AddLowerRow();
    // matrix.AddUpperRow();
    // matrix.AddLeftColum();
    // matrix.AddRightColum();
    // matrix[20][9].SetState(alive);
    // matrix[20][-20].SetState(alive);
    // matrix[-20][20].SetState(alive);
    // matrix[-20][-20].SetState(alive);
    // matrix[0][8].SetState(alive);
    // matrix.AddRightColum();
    // matrix.AddRightColum();
    // matrix.AddRightColum();
    // matrix.AddRightColum();
    // matrix.AddLeftColum();
    // matrix[-1][-2].SetState(alive);

    // std::cout << matrix;
    // std::cout << matrix.GetRows() << " " << matrix.GetColums() << " " << std::endl;
    // std::cout << matrix.GetInitialRow() << " " << matrix.GetInitialColum() << " " << std::endl;
    

    // CellMatrix m;
    // m.AddLowerRow();
    // m.AddLowerRow();
    // m.AddLowerRow();
    // m.AddLowerRow();
    // m.AddRightColum();
    // m.AddRightColum();
    // m.AddRightColum();
    // m.AddRightColum();
    // std::cout << m;

    Border b(3);
    std::string s{"start.txt"};
    Lattice l(s);
    std::cout << l.Population() << std::endl;
    // std::cout << l;
    // l.AccesToMatrix().AddLeftColum();
    // l.AccesToMatrix().AddLeftColum();
    // l.AccesToMatrix().AddUpperRow();
    // l.AccesToMatrix().AddRightColum();
    // l.AccesToMatrix().AddLowerRow();
    
    // l.AccesToMatrix().AddLeftColum();
    // l.AccesToMatrix().AddLeftColum();
    // l.AccesToMatrix().AddUpperRow();
    // l.AccesToMatrix().AddRightColum();
    // l.AccesToMatrix().AddLowerRow();
    
    // ESQUINA SUPERIOR IZQUIERDA
    // std::cout << l;
    // l.AccesToMatrix()[0][1].SetState(alive);
    // l.AccesToMatrix()[1][0].SetState(alive);
    // l.AccesToMatrix()[1][1].SetState(alive);
    // l.AccesToMatrix()[9][9].SetState(alive);
    // l.AccesToMatrix()[9][0].SetState(alive);
    // l.AccesToMatrix()[9][1].SetState(alive);
    // l.AccesToMatrix()[0][9].SetState(alive);
    // l.AccesToMatrix()[1][9].SetState(alive);

    // ESQUINA SUPERIOR DERECHA
    // l.AccesToMatrix()[0][0].SetState(alive);
    // l.AccesToMatrix()[1][0].SetState(alive);
    // l.AccesToMatrix()[9][0].SetState(alive);
    // l.AccesToMatrix()[9][9].SetState(alive);
    // l.AccesToMatrix()[9][8].SetState(alive);
    // l.AccesToMatrix()[0][8].SetState(alive);
    // l.AccesToMatrix()[1][8].SetState(alive);
    // l.AccesToMatrix()[1][9].SetState(alive);

    // ESQUINA INFERIOR IZQUIRDA
    // std::cout << l;
    // l.NextGeneration();
    // std::cout << l;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

#include "../lib/Nodo.h"
#include "../lib/Maze.h"

using namespace std;

int main(int argc, char* argv[]) {
    system("clear");
    if (argc < 2) {
        cerr << "/// Error: el numero de argumentos es incorrecto, debe indicar la ruta del fichero laberinto" << endl;
        return 1;
    }
    string file_name = argv[1];
    fstream file;
    try {
        file.open(file_name);
    } catch (const exception &e) {
        cerr << "/// Error: " << e.what() << endl;
        return 1;
    }
    Maze maze(file);
    maze.Updateheuristic();
    int option{0};
    int s_coor_x{0}, s_coor_y{0};
    int e_coor_x{0}, e_coor_y{0};
    while(true) {
        // system("clear");
        cout << "~~~  MENÚ  ~~~" << endl;
        cout << "[1] Imprimir laberinto." << endl;
        cout << "[2] Imprimir coordenadas." << endl;
        cout << "[3] Imprimir heurística." << endl;
        cout << "[4] Cambiar punto de inicio." << endl;
        cout << "[5] Cambiar punto de destino." << endl;
        cout << "[6] Calcular camino mínimo con A*." << endl;
        cout << "[7] Salir." << endl;
        cout << "Seleccione opción: ";
        cin >> option;
        cout << endl;
        cout << endl;
        Nodo* result;
        vector<Nodo*> path;
        switch (option) {
            case 1:
                maze.Print();
                break;
            case 2:
                maze.PrintIds();
                break;
            case 3:
                maze.PrintHeuristic();
                break;
            case 4:
                cout << "Introduzca las coordenadas x e y del nuevo punto de inicio: ";
                cin >> s_coor_x >> s_coor_y;
                maze.SetStart(s_coor_x, s_coor_y);
                break;
            case 5:
                cout << "Introduzca las coordenadas x e y del nuevo punto de destino: ";
                cin >> e_coor_x >> e_coor_y;
                maze.SetEnd(e_coor_x, e_coor_y);
                break;
            case 6:
                result = maze.RecorridoAEstrella();
                cout << "Coste total: " << result->getRoadCost() << endl;
                cout << "Camino mínimo encontrado: " << endl;
                while (result->getParent() != nullptr) {
                    path.push_back(result);
                    maze.at(result->getId().first, result->getId().second).SetVal(5);
                    result = result->getParent();
                }
                result = path[path.size() - 1]->getParent();
                path.push_back(result);
                for (int i = path.size() - 1; i >= 0; i--) {
                    cout << path[i]->getId().first << "-" << path[i]->getId().second << " ";
                    if (i != 0) cout << "-> ";
                }
                cout << endl;
                maze.Print();
                break;
            case 7:
                cout << "/// FINALIZANDO PROGRAMA." << endl;
                return 0;
                break;
            default:
                cout << "///Error: La opción seleccionada es errónea, debe introducir alguna de las opciones disponibles" << endl;
                cout << "/// PROGRAMA FINALIZADO." << endl;
                return 0;
                break;
        }
        cout << endl;
    }
    return 0;
}
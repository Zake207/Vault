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
    if (argc != 3) {
        string param_1{argv[1]};
        if (argc == 2 && param_1 == "--help") {
            fstream help_file;
            try {
                help_file.open("../files/HelpFile.txt");
            }
            catch(const exception& e) {
                cout << "/// Error: No se pudo abrir el fichero HelpFile.txt" << endl;
                return 2;
            }
            string line;
            while (getline(help_file, line))
                cout << line << endl;
            return 1;
        } else {
            cout << "/// Error: el numero de argumentos es incorrecto, use la opcion --help para más información" << endl;
            return 1;
        }
    }
    string file_in_name = argv[1];
    string file_out_name = argv[2];
    fstream file_in;
    try {
        file_in.open(file_in_name);
    } catch (const exception &e) {
        cerr << "/// Error: " << e.what() << endl;
        return 1;
    }
    Maze maze(file_in);
    maze.Updateheuristic();
    int option{0};
    int heuristic{0};
    int s_coor_x{0}, s_coor_y{0};
    int e_coor_x{0}, e_coor_y{0};
    while(true) {
        cout << "~~~  MENÚ  ~~~" << endl;
        cout << "[1] Imprimir laberinto." << endl;
        cout << "[2] Imprimir coordenadas." << endl;
        cout << "[3] Imprimir heurística." << endl;
        cout << "[4] Cambiar punto de inicio." << endl;
        cout << "[5] Cambiar punto de destino." << endl;
        cout << "[6] Calcular camino mínimo con A*." << endl;
        cout << "[7] Cambiar heurística." << endl;
        cout << "[8] Salir." << endl;
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
                maze.RecorridoAEstrella(file_out_name);
                break;
            case 7:
                cout << "Introduzca la heurística a utilizar (0 o 1): ";
                cin >> heuristic;
                maze.SetHeuristic(heuristic);
                maze.Updateheuristic();
                break;
            case 8:
                cout << "/// FINALIZANDO PROGRAMA." << endl;
                return 0;
                break;
            default:
                cout << "///Error: La opción seleccionada es errónea, debe introducir alguna de las opciones disponibles" << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}
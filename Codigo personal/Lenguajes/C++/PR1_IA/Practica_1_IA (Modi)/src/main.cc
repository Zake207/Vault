#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>

#include "../lib/Nodo.h"
#include "../lib/Grafo.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        if (argc == 2 && string(argv[1]) == "--help") {
            cout << "Uso: ./main <archivo de entrada> <archivo de salida> <modo>" << endl;
            cout << "Modos disponibles:" << endl;
            cout << "  --print: Imprime el grafo" << endl;
            cout << "  --amplitud: Realiza un recorrido en amplitud (BFS) del grafo" << endl;
            cout << "  --profundidad: Realiza un recorrido en profundidad (DFS) del grafo" << endl;
            return 0;
        }
        cerr << "/// Error: el numero de argumentos es incorrecto, use la opcion --help para mas informacion" << endl;
        return 1;
    }
    string file = argv[1];
    string output = argv[2];
    string mode = argv[3];
    vector<Nodo> nodeList;
    int nodeNumber = 0;
    int numero_aristas = 0;
    try {
        ifstream input_file(file);
        if (!input_file) {
            cerr << "File does not exist" << endl;
            return 1;
        }
        string line;
        getline(input_file, line); // Leer el número de nodos
        stringstream ss(line);
        ss >> nodeNumber;
        // Crear nodos
        for (int i = 0; i < nodeNumber; ++i) {
            Nodo node(i);
            nodeList.emplace_back(node);
        }
        // Leer las conexiones y costos
        for (int i = 0; i < nodeNumber; ++i) {
            for (int j = i + 1; j < nodeNumber; ++j) {
                getline(input_file, line);
                double cost;
                stringstream ss(line);
                ss >> cost;
                if (cost >= 0) {
                    nodeList[i].InsertChild(j, cost);
                    nodeList[j].InsertChild(i, cost);
                    ++numero_aristas;
                }
            }
        }
    } catch (const exception& e) {
        cerr << "Unknown error:\n" << e.what() << endl;
        return 1;
    }
    ofstream output_file(output);
    if (!output_file) {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    Grafo grafo(nodeList);
    // grafo.Print();
    output_file << "Numero de nodos: " << nodeNumber << endl;
    output_file << "Numero de aristas: " << numero_aristas << endl;
    if (mode == "--print") {
        grafo.Print();
    } else if (mode == "--amplitud") {
        grafo.RecorridoAmplitud(output_file);
    } else if (mode == "--profundidad") {
        grafo.RecorridoProfundidad(output_file);
    } 
    else {
        cerr << "/// Error: modo no reconocido, use la opcion --help para mas informacion" << endl;
        return 1;
    }
    output_file.close();
    return 0;
}
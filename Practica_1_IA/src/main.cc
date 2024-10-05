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
    if (argc < 3) {
        cerr << "/// Error: el numero de argumentos es incorrecto, use la opcion --help para mas informacion" << endl;
        return 1;
    }
    string file = argv[1];
    string mode = argv[2];
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
    
    Grafo grafo(nodeList);
    // grafo.Print();
    std::ofstream output_file("files/output.txt");
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
#include "../lib/Grafo.h"

    Grafo::Grafo(vector<Nodo>& node_list) {
        node_list_ = node_list;
    }
    void Grafo::Print() {
        for (auto& node : node_list_) {
            cout << node << endl;
        }
    }
    // Recorrido en amplitud (BFS)
    void Grafo::RecorridoAmplitud(std::ofstream &output_file) {
        // Petición de los nodos de inicio y fin
        int pos_ini{0};
        int pos_fin{0};
        cout << "Ingrese el nodo de inicio: ";
        cin >> pos_ini;
        cout << "Ingrese el nodo de fin: ";
        cin >> pos_fin;
        output_file << "Nodo de inicio: " << pos_ini << endl;
        output_file << "Nodo de fin: " << pos_fin << endl;
        output_file << "//////////////////////////////////////////////" << endl;
        queue<Nodo> cola_nodos;
        // Comenzamos el recorrido desde el primer nodo
        Nodo nodo_actual = node_list_[pos_ini];
        nodo_actual.InsertParent(-1, 0);
        cola_nodos.push(nodo_actual);
        // Variables de control
        int iteraciones = 1;
        vector<int> nodos_generados{};
        vector<int> nodos_visitados{};
        // Bucle principal
        while (true) {
            if (cola_nodos.empty()) {
                output_file << "No se ha encontrado una ruta entre los nodos " << pos_ini << " y " << pos_fin << endl;
                break;
            }
            // Extrae el nodo actual de la cola
            Nodo nodo_actual = cola_nodos.front();
            nodos_visitados.push_back(nodo_actual.getId());
            cola_nodos.pop();
            // Imprime el número de iteración
            output_file << "Iteracion: " << iteraciones++ << endl;
            output_file << "\tNodo: " << nodo_actual.getId() << endl;
            // Comprueba si el nodo actual es el nodo final
            if (nodo_actual.getId() == pos_fin) {
                output_file << "//////////////////////////////////////////////" << endl;
                // cout << nodo_actual << endl;
                nodo_actual.getParents().erase(nodo_actual.getParents().begin());
                output_file << "Ruta encontrada: ";
                for (auto& parent : nodo_actual.getParents()) {
                    output_file << parent.first << " ";
                }
                output_file << nodo_actual.getId() << endl;
                int coste = 0;
                for (auto& parent : nodo_actual.getParents()) {
                    coste += parent.second;
                }
                output_file << "Coste: " << coste << endl;
                break;
            }
            // Si no es el nodo final, se extraen los hijos del nodo actual teniendo en cuenta los padres del nodo actual
            else {
                for (auto& child : nodo_actual.getChildren()) {
                    int childId = child.first;
                    double cost = child.second;
                    Nodo childNode = node_list_[childId];
                    for (auto& parent : nodo_actual.getParents()) {
                        childNode.InsertParent(parent.first, parent.second);
                    }
                    childNode.InsertParent(nodo_actual.getId(), cost);
                    bool insertar = true;
                    for (auto& parent : childNode.getParents()) {
                        if (parent.first == childId) {
                            insertar = false;
                        }
                    }
                    if (insertar) {
                        cola_nodos.push(childNode);
                        nodos_generados.push_back(childId);
                    }
                }
                output_file << "\tNodos generados: ";
                for (int i = 0; i < nodos_generados.size(); ++i) {
                    output_file << nodos_generados[i] << " ";
                }
                output_file << endl;
                output_file << "\tNodos visitados: ";
                for (int i = 0; i < nodos_visitados.size(); ++i) {
                    output_file << nodos_visitados[i] << " ";
                }
                output_file << endl;
            }
        }
    }
    // Recorrido en profundidad (DFS)
    void Grafo::RecorridoProfundidad(std::ofstream &output_file) {
        // Petición de los nodos de inicio y fin
        int pos_ini{0};
        int pos_fin{0};
        cout << "Ingrese el nodo de inicio: ";
        cin >> pos_ini;
        cout << "Ingrese el nodo de fin: ";
        cin >> pos_fin;
        output_file << "Nodo de inicio: " << pos_ini << endl;
        output_file << "Nodo de fin: " << pos_fin << endl;
        output_file << "//////////////////////////////////////////////" << endl;
        stack<Nodo> pila_nodos;
        // Comenzamos el recorrido desde el primer nodo
        Nodo nodo_actual = node_list_[pos_ini];
        nodo_actual.InsertParent(-1, 0);
        pila_nodos.push(nodo_actual);
        // Variables de control
        bool encontrado = false;
        int iteraciones = 1;
        vector<int> nodos_generados{};
        vector<int> nodos_visitados{};
        // Bucle principal
        while (!encontrado) {
            if (pila_nodos.empty()) {
                output_file << "No se ha encontrado una ruta entre los nodos " << pos_ini << " y " << pos_fin << endl;
                break;
            }
            Nodo nodo_actual = pila_nodos.top();
            nodos_visitados.push_back(nodo_actual.getId());
            pila_nodos.pop();
            output_file << "Iteracion: " << iteraciones++ << endl;
            output_file << "\tNodo: " << nodo_actual.getId() << endl;
            // Comprueba si el nodo actual es el nodo final
            if (nodo_actual.getId() == pos_fin) {
                output_file << "//////////////////////////////////////////////" << endl;
                // cout << nodo_actual << endl;
                nodo_actual.getParents().erase(nodo_actual.getParents().begin());
                output_file << "Ruta encontrada: ";
                for (auto& parent : nodo_actual.getParents()) {
                    output_file << parent.first << " ";
                }
                output_file << nodo_actual.getId() << endl;
                int coste = 0;
                for (auto& parent : nodo_actual.getParents()) {
                    coste += parent.second;
                }
                output_file << "Coste: " << coste << endl;
                break;
            }
            // Si no es el nodo final, se extraen los hijos del nodo actual teniendo en cuenta los padres del nodo actual
            else {
                for (int i = nodo_actual.getChildren().size() - 1; i >= 0; --i) {
                    int childId = nodo_actual.getChildren()[i].first;
                    double cost = nodo_actual.getChildren()[i].second;
                    Nodo childNode = node_list_[childId];
                    for (auto& parent : nodo_actual.getParents()) {
                        childNode.InsertParent(parent.first, parent.second);
                    }
                    childNode.InsertParent(nodo_actual.getId(), cost);
                    bool insertar = true;
                    for (auto& parent : childNode.getParents()) {
                        if (parent.first == childId) {
                            insertar = false;
                        }
                    }
                    if (insertar) {
                        pila_nodos.push(childNode);
                        nodos_generados.push_back(childId);
                    }
                }
                output_file << "\tNodos generados: ";
                for (int i = 0; i < nodos_generados.size(); ++i) {
                    output_file << nodos_generados[i] << " ";
                }
                output_file << endl;
                output_file << "\tNodos visitados: ";
                for (int i = 0; i < nodos_visitados.size(); ++i) {
                    output_file << nodos_visitados[i] << " ";
                }
                output_file << endl;
            }
        }
    }
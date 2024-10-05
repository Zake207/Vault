import bin.Nodo as Node

class Grafo:
    def __init__(self, list_of_nodes):
        self.grafo = list_of_nodes
    
    def at(self, node) -> Node:
        node = Node.Node(self.grafo[int(node)].GetData(), self.grafo[int(node)].GetChilds(), self.grafo[int(node)].GetFathers())
        return node
    
    def ShowGraph(self) -> None:
        for node in self.grafo:
            print(node)

    def RecorridoAmplitud(self):
        # Pido la posicion inicial y final
        posicion_ini = input("/// Ingrese nodo inicial: ")
        posicion_fin = input("/// Ingrese nodo final: ")
        # Creo el primer nodo
        nodo = self.at(posicion_ini)
        nodo.InsertFather(-1, 0)
        # Lo inserto en la cola
        queue = []
        queue.append(nodo)
        # Variables de control
        encontrado = False
        nodo_visitado = 0
        iteracion = 1
        while (not encontrado):
            # Imprimo la iteracion
            print(f"/// Iteración {iteracion}")
            # Saco el primer nodo de la cola
            nodos_generados = []
            nodo_visitado = queue.pop(0)
            print(f"\tNodo visitado {nodo_visitado.GetData()}")
            # Si es el nodo destino paro la ejecicion
            if (nodo_visitado.GetData() == int(posicion_fin)):
                encontrado = True
            # Si no es el nodo destino meto a sus hijos en la cola
            else:
                childs = nodo_visitado.GetChilds()
                for child in childs:
                    if (child in nodo_visitado.GetFathers()):
                        continue
                    nodo_hijo = self.at(child[0])
                    nodo_hijo.InsertFather(nodo_visitado.GetData(), child[1])
                    queue.append(nodo_hijo)
                    nodos_generados.append(nodo_hijo.GetData())
            print(f"\tNodos generados: {nodos_generados}\n\n")
            iteracion += 1
        print("/// FIN ///")
        print(f"/// Nodos visitados: {iteracion}")
        print(nodo_visitado.GetFathers())
        # camino = []
        # coste = 0
        # for nodo in nodo_visitado.GetFathers():
        #     camino.append(nodo[0])
        #     coste += nodo[1]
        # print(f"/// Camino: {camino}")
        # print(f"/// Coste: {coste}")
        
    
    def RecorridoProfundidad(self):
        pass
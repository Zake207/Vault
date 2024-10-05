import bin.Nodo as Node
import bin.Grafo as Graph
import sys

if (len(sys.argv) < 3):
    print("/// Error: el numero de argumentos es incorrecto, use la opcion --help para mas informacion")
    sys.exit(1)
file = sys.argv[1]
mode = sys.argv[2]
node_list = []
node_number = 0
try:
    with open(f"files/{file}", "r") as input_file:
        node_number = int(input_file.readline().strip())
        for i in range(node_number):
            node_list.append(Node.Node(i, set(), set()))
        for i in range(node_number):
            for j in range(i + 1, node_number):
                cost = float(input_file.readline().strip())
                if (cost >= 0):
                    # print(f"{i}->{j} ==> {cost}")
                    node_list[i].InsertChild(j, cost)
                    node_list[j].InsertChild(i, cost)
except FileNotFoundError:
    print("File does not exist")
except Exception as error:
    print(f"Unknown error:\n{error}")    

grafo = Graph.Grafo(node_list)
# grafo.ShowGraph()
grafo.RecorridoAmplitud()

lista = list()
for i in range(20):
    for j in range(20):
        aux_func = lambda: Func(0,0)
        lista.append(aux_func)
        
def Func(x, y) -> None:
    print(f"{x}, {y}")
    
lista[0]()
    
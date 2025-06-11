![[Pasted image 20250602195453.png]]

## 🧠 **Clasificación de redes según la conmutación**

### 🔁 **Técnicas de conmutación**

1. **Conmutación de Circuitos**
    
    - Se establece un camino físico dedicado entre emisor y receptor antes de que se inicie la comunicación.
        
    - Ejemplo: telefonía tradicional.
        
2. **Almacenamiento y Reenvío (Store & Forward)**
    
    - La información se guarda temporalmente en cada nodo intermedio antes de ser reenviada.
        
    
    Dentro de esta categoría se encuentran:
    
    #### a) **Conmutación de Mensajes**
    
    - Se transmite el **mensaje completo** de nodo en nodo.
        
    - Alta fiabilidad, pero puede generar latencias importantes.
        
    
    #### b) **Conmutación de Paquetes**
    
    - El mensaje se divide en **paquetes más pequeños** que se transmiten de forma independiente.
        
    
    Existen dos tipos:
    
    - **Circuito Virtual**
        
        - Se establece un camino lógico antes de la transmisión.
            
        - Dos variantes:
            
            - **Permanente (PVC)**: camino fijo establecido de forma permanente.
                
            - **Conmutado (SVC)**: camino temporal, se establece por sesión.
                
    - **Datagrama**
        
        - Cada paquete se envía de forma independiente, sin un camino preestablecido.
            
        - Ejemplo: red IP (Internet).
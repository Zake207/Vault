## 📞 **Tecnologías de Voz – Telefonía Digital**

### 🧩 **Digitalización de la voz**

1. **Muestreo (Nyquist)**:
    
    - Frecuencia: 8.000 Hz
        
    - Rango de voz: 300 Hz – 3400 Hz
        
    - Captura: 0 – 4 KHz
        
2. **Cuantificación y codificación**:
    
    - 8 bits por muestra (PCM)
        
    - Se generan flujos binarios que representan la señal analógica.
        
3. **PCM (Pulse Code Modulation)**:
    
    - Método de modulación por pulsos digitales.
        
    - Genera tramas para múltiples canales de voz.
        

---

### 🧮 **PCM – Formatos más usados**

#### ✅ PCM de 30 canales (Europa - E1):

- 30 canales de voz + 1 de señalización + 1 de sincronización.
    
- Cada muestra: 8 bits.
    
- 8.000 tramas/s × 256 bits = **2,048 Mbps**.
    

#### ✅ PCM de 24 canales (EE.UU. - T1):

- 24 canales de voz + 1 bit de entramado.
    
- 8.000 tramas/s × 193 bits = **1,544 Mbps**.
    

---

## 🔀 **Multiplexación**

### 📡 FDM (Frecuencia – obsoleta):

- Usaba bandas de frecuencia distintas por canal.
    
- Incompatible con digitalización.
    

### ⏱️ TDM (Tiempo – actual):

- Asigna "slots" de tiempo a cada canal.
    
- Estructura jerárquica:
    
    - E1 → E2 (4 × E1) → E3 (4 × E2), etc.
        
    - T1 → T2 → T3 (en EE.UU.)
        

---

## 🌐 **Jerarquía Digital Plesiócrona (PDH)**

- Usada en redes clásicas de voz y datos.
    
- Cada región tenía su propia jerarquía (Europa, EE.UU., Japón).
    
- Velocidades típicas:
    
    - E1: 2,048 Mbps (30 canales)
        
    - T1: 1,544 Mbps (24 canales)
        
    - E3: 34,368 Mbps
        
    - T3: 44,736 Mbps
        

---

## 🌍 **SONET / SDH – Jerarquía Digital Síncrona**

### 🎯 Objetivos:

- Unificar redes de voz/datos a nivel mundial.
    
- Optimizar transmisión por fibra óptica.
    
- Facilitar gestión y tolerancia a fallos.
    

### 🧱 Estructura:

- **SONET (ANSI - EE.UU.)**
    
    - Base: 51,84 Mbps → OC-1, OC-3, etc.
        
- **SDH (ITU-T - internacional)**
    
    - Base: 155,52 Mbps → STM-1, STM-4, etc.
        
- Ambos son compatibles entre sí.
    

---

### 🔄 Tramas SONET/SDH:

- Trama SONET STS-1: 810 bytes (90 × 9)
    
- Trama SDH STM-1: 2430 bytes (90 × 9 × 3)
    
- Solo una parte es "carga útil", el resto es _overhead_ (control, sincronización, etc.)
    

### 🛠 Componentes:

- **Repetidores**
    
- **ADMs (Add-Drop Multiplexers)**: inserción/extracción de tramas.
    
- **Optical Cross-Connects**
    
- Uso frecuente de **anillos redundantes** para alta disponibilidad.
    

---

## 🛠️ **Diseño de Redes y Cableado Estructurado**

### 📦 Elementos clave:

- Armario de comunicaciones (rack)
    
- Patch panel, switches, latiguillos, rosetas
    
- Topología típica: estrella
    

### 🧰 Estandarización:

- Categoría del cable (Cat5e, Cat6, Cat8…)
    
- Normativas: EIA-310-D, IEC 60297, DIN 41494
    
- Altura del rack: en unidades U (1U = 4,5 cm)
    

### 🧵 Conexiones RJ-45:

- Estándares de cableado: T568A y T568B
    
- Codificación de pines por colores
    

---

## 🧪 **Prácticas de repaso**

Incluye propuestas de examen como:

- Diseño físico de una red universitaria.
    
- Asignación de ancho de banda.
    
- Propuestas de direccionamiento IP.
    
- Diseño de cableado estructurado para 2 edificios.
    

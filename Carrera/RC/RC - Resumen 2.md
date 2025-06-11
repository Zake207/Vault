## 📡 **Tema general: Señales y medios de transmisión (RDC Parte 2)**

---

### 🔊 **1. Tipos de señales**

- **Analógicas**: varían continuamente (amplitud/frecuencia).
    
- **Digitales**: valores discretos (0 y 1).
    
- **Combinaciones**: analógica-analógica, digital-digital, digital-analógica, etc.
    

---

### 🌈 **2. Espectro electromagnético**

- Clasificación por **frecuencia**:
    
    - VLF: 3 Hz – 30 kHz
        
    - LF, MF, HF, VHF, UHF, SHF, EHF hasta 300 GHz
        
    - Infrarrojo y ultravioleta (hasta 10⁷ Hz)
        
- Frecuencias clave:
    
    - **Radiofrecuencia**: 10 kHz – 300 MHz
        
    - **Microondas**: 300 MHz – 300 GHz
        
    - **Infrarrojo**: 300 GHz – 400 THz
        

---

### 📉 **3. Teorema de Fourier**

Permite descomponer cualquier señal periódica en suma de senos y cosenos.  
➡️ Es clave para:

- Análisis de espectro
    
- Diseño de filtros
    
- Compresión y transmisión eficiente
    

---

### ⏱️ **4. Baudios vs Bps**

- **Baudio** = cambios de estado por segundo (asociado a la línea).
    
- **Bps** = bits por segundo transmitidos (flujo de información).
    
- Fórmulas:
    
    - `Vm = 1/T` (baudios)
        
    - `Vts = Vm * log2(N)` (bps)
        
    - Ejemplo: 2B1Q = 2 bits/símbolo
        

---

### 📶 **5. Capacidad de transferencia**

- **Nyquist (línea ideal)**:
    
    - `C = 2 * W * log₂(N)`
        
    - Eficiencia máxima teórica en bits/Hz
        
- **Shannon-Hartley (línea real)**:
    
    - `C = W * log₂(1 + S/N)`
        
    - Permite calcular capacidad según **relación señal/ruido**
        

---

### 🎼 **6. Digitalización de señales**

1. **Muestreo** (Teorema de Nyquist): `f_muestreo ≥ 2 * AB`
    
2. **Cuantificación**: asigna valores discretos a las muestras
    
3. **Codificación**:
    
    - Manchester, 4B/5B, 8B/10B, PAM, NRZ, etc.
        
    - Se utiliza según medio (fibra, par trenzado, coaxial…)
        

---

### 📡 **7. Modulación**
Es el proceso por el cual **una señal (llamada moduladora)** altera las características de otra señal (llamada **portadora**) para poder **transmitir información** a través de un medio físico.
#### Portadora analógica:

- **AM, FM, PM** (moduladora analógica)
    
- **ASK, FSK, PSK, QAM** (moduladora digital)
    

#### Portadora digital:

- Pulsos modulados: **PAM, PPM, PCM, Delta, etc.**
    

---

### 🌐 **8. Nivel físico (OSI Nivel 1)**

#### Medios guiados:

- **Par trenzado**: UTP, STP, FTP
    
- **Coaxial**: 50/75 Ω, núcleo y malla
    
- **Fibra óptica**:
    
    - Multimodo (MM): LED, cortas distancias
        
    - Monomodo (SM): láser, largas distancias
        
    - Ventanas ópticas: 0.85 μm, 1.3 μm, 1.55 μm
        
    - Atenuación, dispersión, conectores (SC, ST…)
        

#### Medios no guiados:

- **Radioenlaces UHF/SHF** (WiFi, WiMAX)
    
- **Satélite**
    

---

### 📏 **9. Factores que afectan la transmisión**

- Atenuación
    
- Dispersión
    
- Ruido (S/N)
    
- Curvaturas de la fibra
    
- Suciedad, temperatura, envejecimiento
    
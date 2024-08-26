Una copia de seguridad se realiza para asegurar los datos de cierta entidad en caso de accidente, restaurándolos con una serie de planificaciones y procesos, a este compendio de procedimientos se le conoce como la recuperación tras el desastre, mientras que la copia de seguridad se limita a copiar los datos en el lugar designado.
## Tipos
+ Respaldo completo: Se realiza una copia del conjunto de datos, independientemente del tipo de estos.
+ Copia incremental: Se hace a partir de una copia de seguridad completa y solo copia las modificaciones
+ Copia diferencial: También funciona en base a una copia completa y también se actualizan pero estas a adicionan las actualizaciones y cambios detectados en el bloque de datos.
## Métodos de detección
+ A nivel de archivo: Se revisan los archivos en busca de cambios, si detecta alguno, se copia todo el archivo y se envía al almacenamiento de la copia de seguridad.
+ A nivel de bloque: Estructura la info en bloques y si detecta alguna modificación en estos bloques copia el bloque completo.
## Métodos de distribución
+ Compresión: Condensa los archivos en su forma más importante, aprovechado mejor el espacio.
+ Deduplicación: Se eliminan los duplicados de los archivos y solo permanecen los que están más actualizados y puede ser a nivel de archivo o a nivel de bloque.
## Almacenamiento
Los datos pueden guardarse en la nube para no disponer de hardware de alto coste que permita almacenar las copias de seguridad, usando servidores remotos. Por otro lado el almacenamiento físico proporciona control total sobre la información almacenada.

Para poder ser más manejable se suelen automatizar para que estas se realicen cada tanto tiempo. Existen las copias de seguridad continuas las cuales se actualizan cada vez que se modifica la información
## Mirror Backup
Es un tipo de copia de seguridad que se actualiza como las copias completas con el detalle de que refleja el contenido del bloque de datos, si se crea o se borra un archivo se actualiza con la info correspondiente. 



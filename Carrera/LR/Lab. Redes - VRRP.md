[[VRRP.pdf|PDF]]

Es necesaria en las redes la *redundancia en el primer salto*
Para ello existe el protocolo VRRP:

1. Se define una ip virtual que referencia a los routers del portocolo.
2. Uno de ellos se elije como master y los demás como backups
3. El master envía mensajes de *advertisement*
4. Si los backups dejan de recibir estos mensajes el siguiente en la jerarquía pasa a ser el master

Las ventajas de este protocolo es que no requiere reconfigurar nada en los routers.
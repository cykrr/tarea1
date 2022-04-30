# Como compilar y ejecutar la tarea:

Para compilar es necesario GitBash y la herramienta "make", la cual puede ser descargada desde el sig. sitio : [Descargar Make](https://sourceforge.net/projects/ezwinports/files/make-4.3-without-guile-w32-bin.zip/download).
~~Igual puede funcionar en el cmd, pero no cuenta con todas las caracteristicas que quisimos.~~ Agregada función `clrscr` para permitir
uso del comando especifico de cada sistema operativo.
     
El comando para compilar la tarea es el siguiente
```
make
```

Se pueden compilar los casos de prueba con:
```
make tests/map
make tests/list
make tests/cart
```


# Opciones que funcionan y las que no:

* Importar productos funciona bien, no hay problemas al leer el archivo, además separa los datos según las comas

* Exportar esta pendiente

* Agregar productos, funciona bien y no hemos encotrado errores

* Buscar por tipo muestra todos los datos correctamente

* Busca por marca también funciona bien

* Buscar por nombre igual que los otros funciona bien

* Mostrar todos los productos funciona sin problemas

* Agregar al carrito funciona, bien y en caso de que el carrito no exista crea otro con el nombre que se había ingresado además de  sumar el total a medida que se van agregando los productos

* Mostrar carritos, funciona bien, y los datos se mantienen separados

* Concretar compra funciona bien

* Eliminar ultimo producto del carrito

*
  
# Aspectos positivos y a mejorar de cada integrante:
    
* Benjamín: 
     * '+' Buena dirección y planteamiento de prototipos de funciones, paciencia cuando no entendiamos algo (Por parte del resto)
     * '-' División de la carga de trabajo

* Bryam: 
     * '+' Compromiso con ayudar al resto, y preciso a la hora de solucionar los errores
     * '-' Mejorar manejo de código ajeno

* Matias: 
     * '+' Encontrar errores en la logica del programa, participación
     * '-' Practirar las materias antes que tener que aplicarlas en las tareas (estudiar más)

* Nestor: 
     * '+' Buen manejo de la logica en algoritmos, y una redacción clara de la misma 
     * '-' La participación en las reuniones de grupo

# Puntos premio/castigo a cada integrante según el trabajo hecho:

* Benjamin: 3
* Bryam: -1
* Matias: -1
* Nestor: -1

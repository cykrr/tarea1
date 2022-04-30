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

* La opción de ingresar funciona bien, además de contar con margen de error en caso de que ingresen caracteres extras.
* La función de busqueda cuenta con 3 opciones adicionales, donde se elige si buscar por nombre, por artista, por genero 
* Mostrar lista no presenta problema, y muestra las canciones con su respectiva información adicional
* No hay problemas al importar el archivo, la información se guarda correctamente en donde se asigno.
* Exportar funciona bien, aunque para que lo guarde se debe de poner ".csv" fuera de eso funciona bien
* Eliminar las canciones funciona bien, y guarda los cambios en caso de exportar
* Mostrar Playlist funciona, al igual que agregarlas, y si no se crean antes, se crean durante la creación de una canción
  
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

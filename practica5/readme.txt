En el módulo Ruta se usa un contenedor de tipo list para los puntos, porque sólo se van a insertar y borrar los puntos del final de la colección, aunque conlleva que el acceso por índice de GetPunto(int) tenga peor eficiencia.
En el módulo Almacen_Rutas se usa un contenedor de tipo map para almacenar las rutas usando como clave el código de dicha ruta (un string).
Hemos comentado el código que hemos hecho nosotros (Punto, Ruta, Almacen_Rutas)

Grupo B2
Antonio González Maldonado
José Alberto Rodríguez Godoy
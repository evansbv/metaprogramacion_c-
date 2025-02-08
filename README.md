# Implementación de Reflexión y Metaprogramación en C++

    Implementación de Reflexión y Metaprogramación en C++

Evans Balcázar Veizaga<br>
Jorge B. Mostajo Pedraza<br>
Shirley E. Pérez Delgadillo<br>
Rubén Espinoza Orosco<br>


    1. Introducción

En este proyecto, se implementó un sistema de reflexión y metaprogramación en C++ para la creación dinámica de clases y la invocación de métodos sin conocerlos en tiempo de compilación. La elección de C++ como lenguaje se debe a su capacidad para manejar técnicas avanzadas de metaprogramación, como plantillas (templates), SFINAE y macros del preprocesador, permitiendo una implementación eficiente sin sacrificar el rendimiento.
El paradigma orientado a objetos fue clave para estructurar la solución, mientras que la metaprogramación con templates permitió un sistema de reflexión estático y flexible. Además, se incluyeron pruebas unitarias con Google Test para garantizar la robustez del diseño.

    2. Descripción Técnica

Se realizo de la siguiente manera:

             2.1 Generación y Transformación del Código: 
La generación de código se basa en el uso de plantillas y macros para automatizar el registro de clases y métodos en una fábrica centralizada. Se utilizó una estructura de clases donde:
        ◦ Fabrica actúa como el registro global de clases y métodos. 
        ◦ ObjetoBase es la clase base de todas las clases registrables. 
        ◦ Se emplea std::unordered_map para almacenar constructores y punteros a funciones de los métodos registrados. 
        ◦ Macros como REGISTRAR_CLASE y REGISTRAR_METODO facilitan el registro automático de clases y métodos sin afectar el código fuente de cada clase. 
El código resultante permite que nuevas clases y métodos sean registrados sin modificar el sistema central, garantizando flexibilidad y escalabilidad.


             2.2 Funcionamiento en Runtime: 
La reflexión en tiempo de ejecución se logra mediante:
        ◦ Mapas de funciones y constructores: Se almacenan funciones lambda que permiten la creación de instancias dinámicas. 
        ◦ Uso de SFINAE: Se registra automáticamente un método si está presente en la clase. 
        ◦ Invocación Dinámica: Un objeto puede ser creado con Fabrica::instancia().crear("Clase") y su método invocado con Fabrica::instancia().invocarMetodo("Clase::metodo", objeto), sin conocerlos en tiempo de compilación.


    3. Ejecución del programa Principal:
 
./main <br>
Soy un Usuario registrado en el sistema.<br>
Soy un Administrador con permisos avanzados.<br>
 <br>
<br>

    4. Ejecucion de Pruebas en Shell (BASH):
 
mkdir build && cd build<br>
cmake ..<br>
make<br>
./test_fabrica<br>


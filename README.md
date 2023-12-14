# ArmenterosRodriguez_Sergio_Examen.CPP
Examen tema 2, Realizado por Sergio Armenteros Rodríguez
https://github.com/Armenteros05/ArmenterosRodriguez_Sergio_Examen.CPP.git


PARTE 1: PREGUNTAS TIPO TEST.

Pregunta 1: ¿Cuál es la principal diferencia entre la estructura básica del programa en C y C++?
Respuesta 1: b) C utiliza printf y scanf mientras que C++ utiliza std::cout y std::cin.

Pregunta 2: ¿Qué es un espacio de nombres en C++?
Respuesta 2: a) Una característica que permite agrupar entidades como clases, objetos y funciones bajo un nombre.

Pregunta 3: En programación orientada a objetos en C++, ¿qué es una clase?
Respuesta 3: d) Una plantilla para crear objetos, proporciona una definición inicial para el estado (miembros de datos) y el comportamiento (miembros de la función).

Pregunta 4: ¿Qué son los templates en C++?
Respuesta 4: b) Permiten la creación de funciones y clases genéricas, es decir, que pueden trabajar con cualquier tipo de datos.

PARTE DOS: CÓDIGO.
Para todos los apartados he diseñado un código que se adapta a lo requerido en el lenguaje C++, donde se ve el progreso de cada commit y como lo he ido estructurando y luego he modificado el código usando la herramienta externa "Chatgpt", para adptarlo al lenguaje C. Por eso mismo la mayoria de comits y todo el progreso está en C++ y luego en C simplemente está el código modificado para C.

Explicación por pasos de lo realizado en cada apartado:

1:ESTRUCTURA: 
(C++): En este código de C++, se define la estructura Estudiante con los campos requeridos. La función mostrarEstudiante() toma un objeto Estudiante como parámetro y muestra sus campos en la consola. En la función main(), se crea un objeto Estudiante llamado estudiante1, se asignan valores a sus campos y luego se llama a la función mostrarEstudiante() para mostrar los detalles del estudiante. 
(C): En este código en C, la estructura Estudiante se define de manera similar a C++, pero las funciones se mantienen fuera de la estructura. La función mostrarEstudiante() toma un puntero a un objeto Estudiante como parámetro y utiliza printf() para mostrar los detalles del estudiante. En la función main(), se crea un objeto Estudiante llamado estudiante1 y se llama a la función mostrarEstudiante() para mostrar los detalles del estudiante.

2:GESTIÓN DE MATERIAS:
(C++): En este código, se ha añadido un vector de materias a la estructura Estudiante, y se han implementado las funciones agregarMateria y eliminarMateria para gestionar la lista de materias. El programa principal muestra cómo utilizar estas funciones al agregar y eliminar materias, y luego muestra los detalles actualizados del estudiante, también usa un bucle do-while para mostrar un menú que permite al usuario interactuar. 
(C): En C, no hay concepto de clases ni de funciones dentro de estructuras como en C++. En su lugar, podemos utilizar funciones regulares para realizar operaciones sobre los datos de la estructura. Además, en C, no existe un tipo de datos de cadena de caracteres como std::string en C++, por lo que se utilizan arreglos de caracteres (char) para representar cadenas.
(DIFERENCIAS):
Se utilizan arreglos de caracteres (char) en lugar de std::string para representar las cadenas.
La función strcpy se utiliza para copiar cadenas en lugar del operador de asignación = en el caso de cadenas en C++.
Se utiliza strcmp para comparar cadenas en lugar de operadores de comparación directa.
Las funciones scanf y printf se utilizan en lugar de std::cin y std::cout.

3: REGISTRO DE ASISTENCIA:ç
(C++): En este código, la clase Asistencia contiene la fecha, materia y estado de la asistencia. La estructura Estudiante incluye un vector de asistencias. La función registrarAsistencia permite agregar nuevas entradas de asistencia al estudiante, y la función mostrarEstudiante muestra los detalles del estudiante, incluyendo las asistencias registradas, también se ha agregado la opción "Registrar nueva asistencia" en el menú, y se utiliza la función registrarAsistencia para permitir al usuario ingresar la fecha, materia y estado de la nueva asistencia. La función getline se utiliza para leer toda la línea de entrada para la materia, ya que puede contener espacios.
(C): En C, no hay clases ni funciones dentro de estructuras como en C++. En su lugar, utilizamos funciones regulares para realizar operaciones sobre los datos de la estructura. Además, las cadenas de caracteres se representan comúnmente con arreglos de caracteres (char).
(DIFERENCIAS): 
Se utilizan arreglos de caracteres (char) en lugar de std::string para representar las cadenas.
Se utiliza strcpy para copiar cadenas en lugar del operador de asignación = en el caso de cadenas en C++.
Las funciones scanf y printf se utilizan en lugar de std::cin y std::cout.
Las funciones en C no tienen acceso implícito al puntero this como en C++. En este caso, pasamos explícitamente el puntero a la estructura Estudiante como argumento a las funciones.

4: MANEJO DE EXCEPCIONES:
(C++) En este código, las operaciones que pueden lanzar excepciones se colocan dentro de bloques try, y las excepciones se manejan en bloques catch. Esto permite al usuario interactuar con el programa y ver cómo se manejan las excepciones en diferentes situaciones. La excepción AsistenciaException se utiliza para manejar casos específicos relacionados con las asistencias del estudiante.
(C):En C, no hay excepciones como en C++, así que manejar errores generalmente implica devolver códigos de error o imprimir mensajes de error en la salida estándar
(DIFERENCIAS): 
En lugar de excepciones, se utilizan códigos de error para indicar problemas durante la ejecución de la función. Además, se imprime un mensaje de error en la salida estándar.
Se utiliza la función strcmp para comparar cadenas en lugar del operador ==.
En C, se utiliza la función scanf para leer datos desde la entrada estándar. Además, se debe tener cuidado al usar %s en scanf para evitar problemas de desbordamiento de búfer.

CONCLUSIÓN: En base a mi experiencia y a lo explicado anteriormente, podemos observar que C++ contiene muchas más funcionalidades que C, permitiendo una programación más mecanica sencilla y orientada a objetos, para los desarrolladores de CGEA mi recomendación personal sería usar C++ en lugar de C. Como recomendaciones, les diría que podrían mejorar cosas como evaluar y mejorar el rendimiento general del sistema e
identificar y abordar posibles cuellos de botella y problemas de eficiencia, e identificar y priorizar las nuevas funcionalidades o mejoras necesarias.





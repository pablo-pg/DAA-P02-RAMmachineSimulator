# Páctica 2. Simulador de la máquina RAM

## Introducción

Este programa simula una máquina RAM.

## Descripción del problema

Se requiere una máquina que, dadas una serie de instrucciones, una cinta de entrada y una de salida, es capaz de esa serie de instrucciones interactuando con las cintas de tal forma que en la cinta de salida esté el resultado final.  

Todas las instrucciones son las siguientes

| Instrucción | Descripción                                                                                                       |
| ----------- | ----------------------------------------------------------------------------------------------------------------- |
| LOAD op     | El operando se carga en R0.                                                                                       |
| STORE op    | El contenido de R0 se guarda en la memoria según lo indicado en el operando.                                      |
| ADD op      | El operando se suma a R0 y el resultado se almacena en R0. (R0 = R0 + op)                                         |
| SUB op      | El operando se resta a R0 y el resultado se almacena en R0. (R0 = R0 - op)                                        |
| MUL op      | El operando se multiplica con R0 y el resultado se almacena en R0. (R0 = R0 * op)                                 |
| DIV op      | El operando divide a R0 y el resultado se almacena en R0. (R0 = R0 / op)                                          |
| READ op     | Se lee un valor de la cinta de entrada y se almacena en la memoria según lo indicado en el operando.              |
| WRITE op    | Se escribe lo indicado por el operando en la cinta de salida.                                                     |
| JUMP etiq   | El control del programa salta a la instrucción indicada por la etiqueta.                                          |
| JZERO etiq  | El control del programa salta a la instrucción indicada por la etiqueta si el valor de R0 es igual a 0 (R0 == 0). |
| JGTZ etiq   | El control del programa salta a la instrucción indicada por la etiqueta si el valor de R0 es mayor a 0 (R0 > 0).  |
| HALT        | Detiene la ejecución del programa.                                                                                |

## Compilación y ejecución

Compilación:  

```bash
make build
```  

Después de compilar, puede ejecutar manualmente con:

```bash
./simulador <ram_program.ram> <input_tape.in> <output_tape.out>
```  

Además, tiene la opción `-h` que explica el funcionamiento.

## Testing

Se ha implementado un script en bash que indica cuántos programas `.ram` han sido superados exitosamente. Para ejecutarlo introduzca desde el directorio principal del repo:

```bash
./test/run-test.sh
```

## Referencias

[Enunciado de la práctica](https://docs.google.com/document/d/1jM_UtvDmwduBbYUTXiBLwrSr8lhHu-EyYwaIdUIMd_A/edit?usp=sharing)  

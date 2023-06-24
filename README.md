# Sherlock_and_GCD

## Descripción del problema

Sherlock está atascado mientras resuelve un problema: Dada una matriz A = {a1, a2, ... , an}, quiere saber si existe un subconjunto B de esta matriz que siga estas afirmaciones:

✓ B es un subconjunto no vacío.

✓ No existe ningún entero x(x > 1)que divida todos los elementos de B.

✓ No existe ningún elemento de B que sea igual a otro.

_Imprime SÍ si existe tal subconjunto; en caso contrario, imprime NO._

## Solución

Usaremos dos funciones, una la cuál servirá como "filtro" para verificar las afirmaciones que necesitamos, dicha función unicamente compara las entradas y si es igual a 1 imprime directamente el NO, también si existe algún elemento repetido.
La función principal únicamente recibe estos valores e implementar la función booleana.

## Instrucciones de ejecución
1. Compilar el programa como "gcc Sherlock_and_GCD.c"
2. El archivo de los datos de entrada (input4) deberan estar en la misma carpeta o dirección en donde se encuentre el programa en C.
3. Al terminar la ejecución se creará un archivo txt llamado "output4" dentro de la misma dirección del programa en C, el cuál deberá contener la salida esperada del programa.

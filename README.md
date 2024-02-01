[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13544078)
# Práctica 4: Algoritmos de ordenamiento
**Reporte sobre Algoritmos de Ordenación**

### Introducción

La eficiente manipulación de datos es esencial en la programación y el procesamiento de información. Los algoritmos de ordenación desempeñan un papel crucial en este proceso, permitiendo organizar conjuntos de datos de manera eficiente. En este informe, se explorarán varios algoritmos de ordenación, desde los más simples hasta los más avanzados. Analizaremos sus ventajas y desventajas, bibliotecas disponibles en C, estrategias de optimización y concluiremos destacando la importancia de seleccionar el algoritmo adecuado según las necesidades específicas del problema.

### Algoritmos de Ordenación: Pros y Contras

1. **Insertion Sort:**
   - *Pros:* Simple, eficiente para arreglos pequeños o casi ordenados.
   - *Contras:* Complejidad cuadrática, ineficiente para arreglos grandes.

2. **Selection Sort:**
   - *Pros:* Implementación sencilla, operación in situ.
   - *Contras:* Complejidad cuadrática, no estable.

3. **Bubble Sort:**
   - *Pros:* Fácil de implementar, operación in situ.
   - *Contras:* Complejidad cuadrática, ineficiente para arreglos grandes.

4. **Merge Sort:**
   - *Pros:* Complejidad O(n log n), estable, útil para grandes conjuntos de datos.
   - *Contras:* Requiere más memoria adicional.

5. **Quick Sort:**
   - *Pros:* Eficiente en la práctica, complejidad O(n log n) en promedio.
   - *Contras:* No garantiza estabilidad, puede degradarse a O(n^2) en el peor caso.

### Comparación de Algoritmos

#### Complejidad Temporal

- **Merge Sort y Quick Sort:**
  - Tienen complejidades temporales O(n log n) en promedio, ideales para arreglos grandes.
  - Merge Sort es estable, mientras que Quick Sort no garantiza estabilidad.

- **Insertion Sort, Selection Sort y Bubble Sort:**
  - Tienen complejidades cuadráticas, siendo más adecuados para arreglos pequeños o casi ordenados.
  - Insertion Sort es estable, pero Selection Sort y Bubble Sort no garantizan estabilidad.

#### Estabilidad

- **Merge Sort:**
  - Es estable, manteniendo el orden relativo de elementos iguales.

- **Quick Sort:**
  - No garantiza estabilidad, aunque se pueden implementar versiones estables.

- **Insertion Sort, Selection Sort y Bubble Sort:**
  - Insertion Sort es estable, pero los otros no garantizan estabilidad.

#### Uso de Memoria

- **Merge Sort:**
  - Requiere más memoria adicional debido a la fase de fusión.

- **Quick Sort:**
  - Utiliza menos memoria adicional al operar in situ.

- **Insertion Sort, Selection Sort y Bubble Sort:**
  - Operan in situ y requieren menos memoria adicional.

#### Mejor y Peor Caso

- **Merge Sort:**
  - Rendimiento constante en O(n log n) en todos los casos.

- **Quick Sort:**
  - En promedio, O(n log n), pero puede degradarse a O(n^2) en el peor caso.

- **Insertion Sort, Selection Sort y Bubble Sort:**
  - Tienen complejidades cuadráticas tanto en el mejor como en el peor caso.

### Bibliotecas de Ordenación en C

En C, la biblioteca estándar proporciona la función `qsort` que implementa el algoritmo Quick Sort. Además de `qsort`, se pueden encontrar funciones como `bsearch` para búsqueda binaria y otras funciones de manipulación de arreglos en `string.h`. Aunque estas funciones son eficientes, es importante considerar algoritmos específicos según el contexto.

### Estrategias de Optimización

Para optimizar el rendimiento de algoritmos de ordenación, se pueden aplicar diversas estrategias:
- Utilizar algoritmos de ordenación más eficientes, como Quick Sort o Merge Sort.
- Implementar la optimización de la cola en la recursión (Tail Recursion Optimization) cuando sea posible.
- Aplicar técnicas de memorización (Memoization) para evitar recálculos innecesarios.
- Explorar algoritmos iterativos equivalentes o estructuras de datos eficientes.
- Utilizar algoritmos de búsqueda y manipulación de cadenas según las necesidades del problema.

**Análisis del Experimento**

### Experimento 1

Se creó un nuevo archivo, `ordenamientoUno.cpp`, que contenía funciones de algoritmos de ordenación, y se midió el tiempo de ejecución de cada algoritmo durante 30 ciclos. A continuación, se presentan las gráficas del tiempo promedio de cada algoritmo y su desviación estándar.

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-brizavda/assets/141947806/a4a6b5fa-6db9-479d-ae91-5bcd8cb892ab)

Desviación Estandar

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-brizavda/assets/141947806/43fecc83-5043-4d90-b9ee-991180c8e544)

En este experimento, se utilizaron algoritmos con enfoque recursivo. Al principio, las ejecuciones no mostraron problemas con la cantidad de números, pero al llegar al medio millón (500,000), el código comenzó a experimentar tiempos excesivos. En la última ejecución con medio millón de números, el código se detuvo después de 3 horas y 27 minutos sin producir resultados.

### Experimento 2

Se realizaron modificaciones en el archivo anterior, cambiando la recursividad de los algoritmos por bucles iterativos, y se midió el tiempo de ejecución de los 5 algoritmos en 30 ciclos. 
En este experimento, se intentó mejorar la eficiencia de los algoritmos al convertirlos en formas iterativas para reducir el tiempo de ejecución. Sin embargo, surgieron problemas al trabajar con cifras como medio millón, y se decidió limitar este experimento hasta esa cifra. Se observó que Bubble Sort, Insertion Sort y Selection Sort eran los algoritmos más lentos, lo que motivó el siguiente experimento.

### Experimento 3

Se utilizó el archivo `ordenamiento_rec_t.cpp` y se comparó con `ordenamiento_t.cpp` para evaluar los tiempos de ejecución.
Este experimento reveló que tanto Merge Sort como Quick Sort son opciones superiores para arreglos grandes en comparación con Bubble Sort, Insertion Sort y Selection Sort.

### Experimento 4

Se creó un nuevo documento, `ordenamientoDos.cpp`, para realizar la prueba del punto extra, donde se combinaron Merge Sort e Insertion Sort. A continuación, se presentan los resultados del tiempo promedio y la desviación estándar.

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-brizavda/assets/141947806/8e09a51b-759d-448a-ad1f-c0e31afffd33)

Desviación estandar

![image](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-brizavda/assets/141947806/16ea8fff-8d22-4760-9a2b-8da45624cd76)


Este experimento representó una mejora significativa en el tiempo de ejecución en comparación con todos los demás algoritmos al combinar estratégicamente los algoritmos se logro utilizar la eficiencia de Insertion Sort para sublistas pequeñas, igualmente, la estructura recursiva de Merge Sort permite dividir el problema de ordenar una lista en problemas más pequeños, facilitando la implementación y el entendimiento del algoritmo.

**Conclusión**

Los experimentos proporcionaron valiosa información sobre el rendimiento de diversos algoritmos de ordenación. Se observó que las implementaciones recursivas presentaron desafíos en términos de tiempo de ejecución, especialmente para conjuntos de datos más grandes. La transición a enfoques iterativos fue un intento de mitigar estos problemas, aunque se encontraron limitaciones en cifras considerables.

La comparación entre Merge Sort, Quick Sort y los algoritmos más simples resaltó la eficiencia de los primeros para conjuntos de datos extensos. La combinación de Merge Sort e Insertion Sort en el último experimento demostró ser una estrategia efectiva para mejorar el rendimiento, sugiriendo posibles enfoques híbridos para la optimización de algoritmos de ordenación. Estos resultados respaldan la importancia de seleccionar y adaptar algoritmos según las características específicas del problema y las limitaciones del entorno de ejecución.

# Algoritmos y Estructuras de Datos 🚀

Este repositorio contiene las implementaciones prácticas y el seguimiento teórico de la materia **Algoritmos y Estructuras de Datos**. El objetivo principal es profundizar en el diseño de algoritmos eficientes, el análisis de complejidad y la creación desde cero de Tipos Abstractos de Datos (TAD) utilizando memoria dinámica en **C/C++**.

---

## 📋 Estructura de la Materia & Estado del Arte

A continuación se detallan las unidades conceptuales de la materia y el estado de su implementación en este repositorio:

### 🔹 Unidad 1: Fundamentos y Complejidad
* [ ] **Análisis de Algoritmos:** Conceptos fundamentales de eficiencia.
* [ ] **Notación O Grande (Big O Notation):** Análisis de complejidad temporal y espacial en el peor caso.
* [ ] **Técnicas Algorítmicas:** Enfoques de resolución de problemas (Divide y vencerás, Greedy, etc.).

### 🔹 Unidad 2: Especificación y Estructuras Lineales
* [ ] **Especificación Algebraica:** Definición formal y axiomática de los TAD.
* [x] **Listas Simplemente Enlazadas:** Estructura base mediante nodos y punteros.
* [ ] **Listas Circulares:** Variación enlazada donde el último nodo apunta al primero.
* [x] **Pila (Stack):** Implementación de comportamiento LIFO basada en listas enlazadas.
* [x] **Fila / Cola (Queue):** Implementación de comportamiento FIFO basada en listas enlazadas.

### 🔹 Unidad 3: Estructuras No Lineales y Gráficas
* [ ] **Árboles:** Conceptos generales y estructuras jerárquicas.
* [x] **Árbol Binario (AB):** Implementación base y recorridos.
* [ ] **Árbol de Huffman:** Algoritmo de compresión de datos.
* [ ] **Grafos:** Representación de relaciones complejas (Matrices/Listas de adyacencia).
  * [ ] Recorrido en Profundidad (DFS) y Recorrido en Amplitud (BFS).
  * [ ] Algoritmo de Dijkstra (Caminos mínimos desde un origen).
  * [ ] Algoritmo de Floyd-Warshall (Caminos mínimos entre todos los pares).

### 🔹 Unidad 4: Algoritmos de Ordenación
* [ ] **Métodos de Ordenamiento:** Implementación analítica de algoritmos clásicos para organización de arreglos/listas (por ejemplo: Bubble Sort, Insertion Sort, Selection Sort, Merge Sort o Quick Sort).

### 🔹 Unidad 5: Estructuras Avanzadas de Búsqueda
* [ ] **ABB (Árbol de Búsqueda Binaria):** Árboles binarios con propiedades de orden.
* [ ] **Árbol AVL:** Árboles binarios de búsqueda auto-balanceados.
* [ ] **Árboles Multivía:** Conceptos de nodos con múltiples hijos.
* [ ] **Árboles 2-3 y 2-3-4:** Estructuras de búsqueda balanceadas avanzadas.

---

## 🛠️ Tecnologías y Conceptos Clave

* **Lenguajes:** C / C++
* **Gestión de Memoria:** Alojamientos dinámicos en tiempo de ejecución utilizando punteros (`malloc`/`free` en C o `new`/`delete` en C++).
* **Eficiencia:** Diseño de código estructurado teniendo en cuenta el impacto de la notación asintótica O grande.

---

## 🚀 Cómo compilar y ejecutar

Para clonar este repositorio y probar cualquiera de las implementaciones locales:

```bash
# 1. Clonar el repositorio
git clone [https://github.com/Cesar24-orellana/Tps-Algoritmo.git]

# 2. Entrar a la carpeta
cd TU_REPOSITORIO

# 3. Ejemplo de compilación para un TAD específico (ej. Pila)
g++ -o programa_pila main_pila.cpp

# 4. Ejecutar el binario generado
./programa_pila
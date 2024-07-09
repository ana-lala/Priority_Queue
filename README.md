# ColaMedieval Class

## Overview

The `ColaMedieval` class simulates a medieval queue where individuals, categorized as "Noble" or "Plebeian," are prioritized based on their social class.

## Implementation Details

- **Constructor (`ColaMedieval()`)**: Initializes an empty queue.
  
- **Destructor (`~ColaMedieval()`)**: Clears all allocated memory upon object destruction.

- **Copy Constructor (`ColaMedieval(const ColaMedieval &c)`)** and **Assignment Operator (`operator=`)**: Allow copying of queues while maintaining correct internal pointers and sizes.

## Methods

### `Agregar(std::string nombre, std::string claseSocial)`

Adds an individual to the queue based on their social class ("Noble" or "Plebeian"). Nobles are inserted at the front of the queue, while Plebeians are inserted at the end.

### `Eliminar()`

Removes the front individual from the queue.

### `ObtenerTam()`, `ObtenerTamPlebeyo()`, `ObtenerTamNoble()`

Retrieves the total size of the queue and the counts of Nobles and Plebeians.

### `ObtenerFondo()`, `ObtenerFrente()`, `ObtenerClaseSocialFrente()`

Retrieves the name of the individual at the back and front of the queue, and their social class.

### `EstaVacia()`

Checks if the queue is empty.

### `Vaciar()`

Empties the queue by deleting all elements.

### `Imprimir()`, `ImprimirSinFrente()`

Prints the queue, optionally omitting the front individual in `ImprimirSinFrente()`.

## Exception Handling

- **`ColaVacia`**: Custom exception thrown when attempting to perform operations on an empty queue.

## How it's a Priority Queue

The `ColaMedieval` class implements a priority queue by:
- Prioritizing Nobles over Plebeians upon insertion (`Agregar()` method).
- Ensuring Nobles are always served first when they are present in the queue.

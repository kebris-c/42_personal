# Instrucciones para probar get_next_line

Este conjunto de archivos te permitirá probar exhaustivamente tu implementación de `get_next_line`. A continuación, te explico cómo usar el main de pruebas y el Makefile proporcionados.

## Archivos proporcionados

1. `main.c`: Programa principal que crea varios archivos de prueba y ejecuta tests tanto para la parte obligatoria como para la parte bonus.
2. `Makefile`: Facilita la compilación y ejecución de las pruebas con diferentes configuraciones.

## Cómo usar el Makefile

### Compilar la versión obligatoria
```bash
make
```
Esto generará un ejecutable llamado `test_gnl` compilado con `BUFFER_SIZE=42`.

### Compilar la versión bonus
```bash
make bonus
```
Esto generará un ejecutable llamado `test_gnl_bonus` compilado con `BUFFER_SIZE=42` y activará los tests para múltiples descriptores.

### Probar con diferentes tamaños de buffer
```bash
make test_sizes
```
Esto ejecutará pruebas con `BUFFER_SIZE` de 1, 42 y 9999, y también probará la versión bonus.

### Limpiar archivos generados
```bash
make clean    # Elimina archivos objeto y archivos de prueba
make fclean   # Elimina todo, incluyendo ejecutables
make re       # Reconstruye el proyecto desde cero
```

## Pruebas incluidas en el main.c

1. **Test Lectura Básica**: Lee un archivo normal con varias líneas.
2. **Test Archivo Sin Newline**: Prueba un archivo que no termina con salto de línea.
3. **Test Línea Larga**: Verifica la lectura de líneas muy largas que superan el BUFFER_SIZE.
4. **Test Archivo Vacío**: Verifica el comportamiento con un archivo sin contenido.
5. **Test Líneas Vacías**: Prueba con un archivo que contiene líneas en blanco (solo '\n').
6. **Test FD Inválido**: Verifica la respuesta al pasar descriptores de archivo inválidos.
7. **Test Múltiples Descriptores**: (Solo en la versión bonus) Alterna entre varios archivos abiertos.
8. **Test Stdin**: Permite probar la lectura desde la entrada estándar (activado con el argumento `-stdin`).

## Cómo ejecutar pruebas adicionales

### Prueba con stdin
```bash
./test_gnl -stdin
# o
./test_gnl_bonus -stdin
```

### Prueba con un BUFFER_SIZE personalizado
```bash
make BUFFER_SIZE=1234
```

### Probar con Valgrind para detectar fugas de memoria
```bash
valgrind --leak-check=full --show-leak-kinds=all ./test_gnl
```

## Verifica estos aspectos

Al revisar los resultados de las pruebas, presta especial atención a:

1. **¿Todas las líneas se leen correctamente?** Verifica que el número de líneas y su contenido sean los esperados.
2. **¿Se manejan correctamente los casos límite?** Archivos vacíos, sin newline final, etc.
3. **¿Funciona con diferentes BUFFER_SIZE?** Desde muy pequeños (1) hasta muy grandes (9999).
4. **¿Hay fugas de memoria?** Usa Valgrind para verificar.
5. **¿Funciona la versión bonus con múltiples descriptores?** Verifica que mantiene el contexto correctamente.

Si todo funciona según lo esperado, ¡estás listo para entregar tu proyecto!
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:41:51 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/16 10:44:41 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifdef BONUS
# include "get_next_line_bonus.h"
#else
# include "get_next_line.h"
#endif

// Función para crear archivos de prueba
void create_test_files(void)
{
    int fd;
    
    // Archivo normal con múltiples líneas
    fd = open("test_normal.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "Esta es la línea 1\n", 19);
    write(fd, "Esta es la línea 2\n", 19);
    write(fd, "Esta es la línea 3\n", 19);
    close(fd);
    
    // Archivo que termina sin newline
    fd = open("test_sin_nl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "Esta línea termina con salto\n", 29);
    write(fd, "Esta línea no termina con salto", 31);
    close(fd);
    
    // Archivo con una línea larga
    fd = open("test_linea_larga.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "Esta es una línea muy larga para probar el comportamiento con buffers pequeños. ", 78);
    write(fd, "Continuación de la línea larga para asegurar que supera cualquier BUFFER_SIZE razonable. ", 87);
    write(fd, "La línea sigue y sigue para probar que tu función maneja correctamente líneas muy largas.\n", 86);
    write(fd, "Esta es una segunda línea más corta.\n", 37);
    close(fd);
    
    // Archivo vacío
    fd = open("test_vacio.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    close(fd);
    
    // Archivo con líneas vacías
    fd = open("test_lineas_vacias.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "\n\n\n", 3);
    write(fd, "Línea después de varias líneas vacías\n", 38);
    write(fd, "\n", 1);
    close(fd);
}

// Test básico de lectura de un archivo
void test_lectura_basica(void)
{
    int fd;
    char *line;
    int line_count = 0;
    
    printf("\n=== TEST LECTURA BÁSICA ===\n");
    fd = open("test_normal.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo test_normal.txt\n");
        return;
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[Línea %d]: %s", ++line_count, line);
        free(line);
    }
    
    close(fd);
    printf("Total de líneas leídas: %d\n", line_count);
}

// Test para archivo sin newline al final
void test_sin_newline(void)
{
    int fd;
    char *line;
    int line_count = 0;
    
    printf("\n=== TEST ARCHIVO SIN NEWLINE AL FINAL ===\n");
    fd = open("test_sin_nl.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo test_sin_nl.txt\n");
        return;
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[Línea %d]: %s", ++line_count, line);
        free(line);
    }
    
    close(fd);
    printf("Total de líneas leídas: %d\n", line_count);
}

// Test para archivo con línea larga
void test_linea_larga(void)
{
    int fd;
    char *line;
    int line_count = 0;
    
    printf("\n=== TEST LÍNEA LARGA ===\n");
    fd = open("test_linea_larga.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo test_linea_larga.txt\n");
        return;
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[Línea %d] (longitud: %lu): %s", ++line_count, strlen(line), line);
        free(line);
    }
    
    close(fd);
    printf("Total de líneas leídas: %d\n", line_count);
}

// Test para archivo vacío
void test_archivo_vacio(void)
{
    int fd;
    char *line;
    
    printf("\n=== TEST ARCHIVO VACÍO ===\n");
    fd = open("test_vacio.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo test_vacio.txt\n");
        return;
    }
    
    line = get_next_line(fd);
    if (line == NULL)
        printf("OK: Archivo vacío devuelve NULL\n");
    else
    {
        printf("ERROR: Archivo vacío no devuelve NULL. Devuelve: %s\n", line);
        free(line);
    }
    
    close(fd);
}

// Test para archivo con líneas vacías
void test_lineas_vacias(void)
{
    int fd;
    char *line;
    int line_count = 0;
    
    printf("\n=== TEST LÍNEAS VACÍAS ===\n");
    fd = open("test_lineas_vacias.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error al abrir el archivo test_lineas_vacias.txt\n");
        return;
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("[Línea %d] (longitud: %lu): '%s'", ++line_count, strlen(line), line);
        free(line);
    }
    
    close(fd);
    printf("Total de líneas leídas: %d\n", line_count);
}

// Test para descriptores de archivo inválidos
void test_fd_invalido(void)
{
    char *line;
    
    printf("\n=== TEST FD INVÁLIDO ===\n");
    
    // FD negativo
    line = get_next_line(-1);
    if (line == NULL)
        printf("OK: FD negativo devuelve NULL\n");
    else
    {
        printf("ERROR: FD negativo no devuelve NULL\n");
        free(line);
    }
    
    // FD que no existe
    line = get_next_line(42);
    if (line == NULL)
        printf("OK: FD inexistente devuelve NULL\n");
    else
    {
        printf("ERROR: FD inexistente no devuelve NULL\n");
        free(line);
    }
}

// Test para la parte bonus (múltiples descriptores)
void test_multiple_fd(void)
{
    int fd1, fd2, fd3;
    char *line;
    
    printf("\n=== TEST MÚLTIPLES DESCRIPTORES (BONUS) ===\n");
    
    fd1 = open("test_normal.txt", O_RDONLY);
    fd2 = open("test_sin_nl.txt", O_RDONLY);
    fd3 = open("test_linea_larga.txt", O_RDONLY);
    
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("Error al abrir uno o más archivos\n");
        return;
    }
    
    // Primera ronda de lecturas
    printf("\n--- Primera ronda ---\n");
    line = get_next_line(fd1);
    printf("fd1: %s", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("fd2: %s", line);
    free(line);
    
    line = get_next_line(fd3);
    printf("fd3: %s", line);
    free(line);
    
    // Segunda ronda de lecturas
    printf("\n--- Segunda ronda ---\n");
    line = get_next_line(fd1);
    printf("fd1: %s", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("fd2: %s", line);
    free(line);
    
    line = get_next_line(fd3);
    printf("fd3: %s", line);
    free(line);
    
    close(fd1);
    close(fd2);
    close(fd3);
}

// Función interactiva para probar la lectura desde stdin
void test_stdin(void)
{
    char *line;
    
    printf("\n=== TEST LECTURA DESDE STDIN ===\n");
    printf("Escribe líneas (presiona Ctrl+D para terminar):\n");
    
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        printf("Leído: %s", line);
        free(line);
    }
    
    printf("\nLectura de stdin finalizada\n");
}

int main(int argc, char **argv)
{
    // Crear archivos de prueba
    create_test_files();
    
    printf("*** TESTS GET_NEXT_LINE ***\n");
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
    
    // Ejecutar tests básicos
    test_lectura_basica();
    test_sin_newline();
    test_linea_larga();
    test_archivo_vacio();
    test_lineas_vacias();
    test_fd_invalido();
    
    // Ejecutar test de la parte bonus solo si la bandera BONUS está definida
    #ifdef BONUS
    test_multiple_fd();
    #else
    printf("\n=== TEST MÚLTIPLES DESCRIPTORES (BONUS) ===\n");
    printf("Skipped: Compilar con -D BONUS para ejecutar este test\n");
    #endif
    
    // Ejecutar test de stdin solo si se pasa la bandera -stdin
    if (argc > 1 && strcmp(argv[1], "-stdin") == 0)
        test_stdin();
    else
        printf("\n=== TEST STDIN OMITIDO ===\n(Ejecuta con argumento -stdin para probar)\n");
    
    printf("\n*** TESTS FINALIZADOS ***\n");
    
    return (0);
}

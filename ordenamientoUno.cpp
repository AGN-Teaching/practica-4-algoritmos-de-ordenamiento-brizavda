#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Prototipos de funciones
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int n);
int partition(int arr[], int low, int high);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <tamaño_del_arreglo> <número_de_arreglos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);  // Tamaño del arreglo
    int m = atoi(argv[2]);  // Número de arreglos a generar y ordenar

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Abrir archivo de salida
    FILE *outputFile = fopen("resultados.txt", "w");
    if (outputFile == NULL) {
        perror("Error al abrir el archivo de salida");
        return 1;
    }

    // Encabezado del archivo de salida
    fprintf(outputFile, "#Ejec.\tis_t\tss_t\tbs_t\tms_t\tqs_t\n");

    double is_times[m], ss_times[m], bs_times[m], ms_times[m], qs_times[m];

    // Generar y ordenar m arreglos
    for (int ejecucion = 0; ejecucion < m; ejecucion++) {
        // Generar arreglo Ai con n números aleatorios entre 1 y 10n
        int Ai[n];
        for (int i = 0; i < n; i++) {
            Ai[i] = rand() % (10 * n) + 1;
        }

        // Copiar el arreglo Ai en Bi para cada algoritmo
        int Bi[n];
        for (int i = 0; i < n; i++) {
            Bi[i] = Ai[i];
        }

        // Medir el tiempo de ejecución de Insertion Sort
        clock_t start = clock();
        insertionSort(Bi, n);
        clock_t end = clock();
        is_times[ejecucion] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medir el tiempo de ejecución de Selection Sort
        for (int i = 0; i < n; i++) {
            Bi[i] = Ai[i];
        }
        start = clock();
        selectionSort(Bi, n);
        end = clock();
        ss_times[ejecucion] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medir el tiempo de ejecución de Bubble Sort
        for (int i = 0; i < n; i++) {
            Bi[i] = Ai[i];
        }
        start = clock();
        bubbleSort(Bi, n);
        end = clock();
        bs_times[ejecucion] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medir el tiempo de ejecución de Merge Sort
        for (int i = 0; i < n; i++) {
            Bi[i] = Ai[i];
        }
        start = clock();
        mergeSort(Bi, n);
        end = clock();
        ms_times[ejecucion] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medir el tiempo de ejecución de Quick Sort
        for (int i = 0; i < n; i++) {
            Bi[i] = Ai[i];
        }
        start = clock();
        quickSort(Bi, n);
        end = clock();
        qs_times[ejecucion] = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Escribir resultados en el archivo de salida
        fprintf(outputFile, "%d\t%f\t%f\t%f\t%f\t%f\n", ejecucion + 1, is_times[ejecucion], ss_times[ejecucion], bs_times[ejecucion], ms_times[ejecucion], qs_times[ejecucion]);
    }

    // Calcular promedio y desviación estándar para cada algoritmo
    double is_avg = 0, ss_avg = 0, bs_avg = 0, ms_avg = 0, qs_avg = 0;
    for (int i = 0; i < m; i++) {
        is_avg += is_times[i];
        ss_avg += ss_times[i];
        bs_avg += bs_times[i];
        ms_avg += ms_times[i];
        qs_avg += qs_times[i];
    }

    is_avg /= m;
    ss_avg /= m;
    bs_avg /= m;
    ms_avg /= m;
    qs_avg /= m;

    double is_std = 0, ss_std = 0, bs_std = 0, ms_std = 0, qs_std = 0;
    for (int i = 0; i < m; i++) {
        is_std += pow(is_times[i] - is_avg, 2);
        ss_std += pow(ss_times[i] - ss_avg, 2);
        bs_std += pow(bs_times[i] - bs_avg, 2);
        ms_std += pow(ms_times[i] - ms_avg, 2);
        qs_std += pow(qs_times[i] - qs_avg, 2);
    }

    is_std = sqrt(is_std / m);
    ss_std = sqrt(ss_std / m);
    bs_std = sqrt(bs_std / m);
    ms_std = sqrt(ms_std / m);
    qs_std = sqrt(qs_std / m);

    // Escribir estadísticas en el archivo de salida
    fprintf(outputFile, "\n\n#Estadísticas\tis_prom\tis_std\tss_prom\tss_std\tbs_prom\tbs_std\tms_prom\tms_std\tqs_prom\tqs_std\n");
    fprintf(outputFile, "#Estadísticas\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", is_avg, is_std, ss_avg, ss_std, bs_avg, bs_std, ms_avg, ms_std, qs_avg, qs_std);

    // Cerrar el archivo de salida
    fclose(outputFile);

    return 0;
}

// Implementación de algoritmos de ordenamiento

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeSort(int arr[], int n) {
    int current_size;
    int left_start;

    for (current_size = 1; current_size <= n - 1; current_size = 2 * current_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
            int mid = left_start + current_size - 1;
            int right_end = (left_start + 2 * current_size - 1 < n - 1) ? (left_start + 2 * current_size - 1) : (n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Fusionar los arreglos temporales de nuevo en arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int n) {
    int stack[n];
    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        int pi = partition(arr, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>

void merge_sort_insertion_sort(std::vector<int>& arr, int k);
void insertion_sort(std::vector<int>& arr);
void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right);
void generate_random_array(std::vector<int>& arr, int n);
void write_times_to_file(const std::vector<double>& times, double average_time, double standard_deviation, const std::string& filename);

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <m>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);

    srand(time(0)); // Inicializar la semilla para la generación de números aleatorios

    std::vector<double> execution_times;

    for (int i = 0; i < m; ++i) {
        std::vector<int> Ai, Bi;

        generate_random_array(Ai, n);
        Bi = Ai; // Copiar el arreglo Ai a Bi

        clock_t start_time = clock();
        merge_sort_insertion_sort(Bi, 5); // Puedes ajustar el valor de 'k'
        clock_t end_time = clock();

        double execution_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        execution_times.push_back(execution_time);
    }

    // Calcular el tiempo promedio y la desviación estándar
    double sum = 0.0;
    for (double time : execution_times) {
        sum += time;
    }

    double average_time = sum / m;

    double sum_squared_diff = 0.0;
    for (double time : execution_times) {
        sum_squared_diff += pow(time - average_time, 2);
    }

    double standard_deviation = sqrt(sum_squared_diff / m);

    write_times_to_file(execution_times, average_time, standard_deviation, "tiempos.txt");

    std::cout << "Tiempo promedio: " << average_time << " segundos" << std::endl;
    std::cout << "Desviación estándar: " << standard_deviation << " segundos" << std::endl;

    return 0;
}

void merge_sort_insertion_sort(std::vector<int>& arr, int k) {
    if (arr.size() <= k) {
        insertion_sort(arr);
    } else {
        int mid = arr.size() / 2;
        std::vector<int> left_sublist(arr.begin(), arr.begin() + mid);
        std::vector<int> right_sublist(arr.begin() + mid, arr.end());

        merge_sort_insertion_sort(left_sublist, k);
        merge_sort_insertion_sort(right_sublist, k);

        merge(arr, left_sublist, right_sublist);
    }
}

void insertion_sort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

void merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void generate_random_array(std::vector<int>& arr, int n) {
    arr.clear();
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % (10 * n) + 1);
    }
}

void write_times_to_file(const std::vector<double>& times, double average_time, double standard_deviation, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (double time : times) {
            file << time << std::endl;
        }
        file << "Tiempo promedio: " << average_time << " segundos" << std::endl;
        file << "Desviación estándar: " << standard_deviation << " segundos" << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}


#include <iostream>
#include <random>

// Generates an array of random size with random elements
void randomizeArray(int*& array, int& size){
    // Generates random seeds to number generator.
    std::random_device rd;
    // Use the 'mt19937' object as the random number generator
    std::mt19937 rng(rd());
    // Define a uniform distribution
    std::uniform_int_distribution<> distSize(1, 100);
    std::uniform_int_distribution<> distArray(1, 1000);
    size = distSize(rng);
    array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = distArray(rng);
    }
}

void insertionSort(int*& array, int size, int& operations){
    int key;
    int i;
    for (int j = 1; j < size; j++){
        key = array[j];
        i = j - 1;
        while (i >= 0 and array[i] > key){
            array[i + 1] = array[i];
            i--;
            operations++;
        }
        array[i + 1] = key;
        operations++;
    }
}

void printArray(int* array, int size){
    std::cout << "[";
        for (int i = 0; i < size; i++){
            std::cout << array[i];
            if (i + 1 < size){
                std::cout << ", ";
            }
        }
        std::cout << "]" << '\n';
}

int main(){
    int* array;
    int size;
    char option;
    // Counter of Insertion Sort operations
    int operations;
    do {
        randomizeArray(array, size);
        std::cout << "Original array:" << '\n';
        printArray(array, size);
        std::cout << std::endl;
        operations = 0;
        insertionSort(array, size, operations);
        std::cout << "After sorting:" << '\n';
        printArray(array, size);
        std::cout << "Number of operations: " << operations <<'\n';
        std::cout << std::endl;
        std::cout << "Do you want to continue generating arrays [y/n]? ";
        std::cin >> option;
        std::cout << std::endl;
        delete[] array;
    } while (option == 'y');
    return 0;
}

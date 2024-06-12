#include<iostream>
#include<cstdlib>

using namespace std;

//Random array generator
void randomArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

//Stampa dell'array
void printArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Insertion sort
void insertionSort(int* arr, int size){
    for(int i = 1; i < size; i++){
        int toOrder = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > toOrder){
            cout << "Sposto " << arr[j] << " in posizione " << j + 1 << endl;
            arr[j + 1] = arr[j];
            j--;
        }
        cout << "Posiziono " << toOrder << " in posizione " << j + 1 << endl;
        arr[j + 1] = toOrder;
    }
}

//Selection sort
void selectionSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                cout << "Allora il minimo non è " << arr[min] << " ma è " << arr[j] << endl;
                min = j;
            }
        }
        cout << "Fine passata, scambio " << arr[i] << " con " << arr[min] << endl;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubbleSort(int* arr, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(arr[j] > arr[j+1]){
                cout << "Scambio " << arr[j] << " con " << arr[j+1] << endl;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortOptimized(int* arr, int size){
    bool swapped = true;
    for(int i=0; i<size && swapped; i++){
        swapped = false;
        for(int j=0; j<size-1; j++){
            if(arr[j] > arr[j+1]){
                cout << "Scambio " << arr[j] << " con " << arr[j+1] << endl;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
    }
}

void merge(int* arr, int start, int middle, int end){
    cout << "Merge " << start << " " << middle << " " << end << endl;
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int* left = new int[n1];
    int* right = new int[n2];

    for(int i = 0; i < n1; i++){
        cout << "Inserisco array[" << start + i << "]=" << arr[start + i] << " in left[" << i << "]" << endl;
        left[i] = arr[start + i];
    }

    for(int i = 0; i < n2; i++){
        cout << "Inserisco array[" << middle + 1 + i << "]=" << arr[middle + 1 + i] << " in right[" << i << "]" << endl;
        right[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            cout << "Assegno left[" << i << "]= " << left[i] << " a arr[" << k << "]" << endl;
            arr[k] = left[i];
            i++;
        }
        else{
            cout << "Assegno right[" << j << "]= " << right[j] << " a arr[" << k << "]" << endl;
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        cout << "Left non è finito, assegno left[" << i << "]= " << left[i] << " a arr[" << k << "]" << endl;
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        cout << "Right non è finito, assegno right[" << j << "]= " << right[j] << " a arr[" << k << "]" << endl;
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(int* arr, int start, int end){
    if(start < end){
        int middle = (start + end) / 2;
        mergeSortRecursive(arr, start, middle);
        mergeSortRecursive(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}


void quickSort(int* arr, int start, int end){
    cout << "Quick sort start: " << start << " end: " << end << endl;
    if(start < end){
        cout << "Pivot: arr[" << end << "]=" << arr[end] << endl;
        int pivot = arr[end];
        //Da qui in poi è la partition sostanzialmente
        int i = start - 1;
        for(int j = start; j < end; j++){
            if(arr[j] < pivot){
                cout << "arr["<< j <<"]=" << arr[j] << " < pivot=" << pivot << ". Scambio con arr[" << i <<"]" << endl;
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        //Qui finisce la partition
        //Stampo la posizione finale del pivot con il suo valore
        cout << "L'elemento " << arr[i+1] << " è ora alla posizione corretta di indice " << i+1 << endl;
        quickSort(arr, start, i);
        quickSort(arr, i + 2, end);
    }
}

int main(){
    //Init random
    srand(time(NULL));
    //Crea un array random
    int size = 10;
    int* arr = new int[size];
    //Genero un array di numeri da 1 a 10 in ordine decrescente
    for(int i = 0; i < size; i++){
        arr[i] = size - i;
    }
    //randomArray(arr, size);
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
}
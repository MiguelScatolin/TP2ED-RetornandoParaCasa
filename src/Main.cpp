#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Base.h"
#include "Stack.h"

void populateBases(Base *bases, std::ifstream &file, int numberOfBases) {
    for (int i = 0; i < numberOfBases; i++) {
            int distance;
            std::string name;
            file >> name;
            file >> distance;

            Base newBase = Base(name, distance);

            bases[i] = newBase;
        }
}

void insertionSort(Base *bases, int numberOfBases) {
    int i,j;
    Base aux;
    for(i = 1; i < numberOfBases; i++) {
        aux = bases[i];
        j = i - 1;

        while(j >= 0 && aux.distance > bases[j].distance) {
            bases[j + 1] = bases[j];
            j--;
        }

        bases[j + 1] = aux;
    }
}

Base *merge(Base leftList[], Base rightList[], int numberOfLeftElements, int numberOfRightElements) {
    int i = 0, j = 0, k = 0;
    Base* sortedMerge = new Base[numberOfRightElements + numberOfLeftElements];

    while (i < numberOfLeftElements && j < numberOfRightElements) {
        if (leftList[i].distance >= rightList[j].distance) {
            sortedMerge[k] = leftList[i];
            i++;
        } else {
            sortedMerge[k] = rightList[j];
            j++;
        }
        k++;
    }

    if (k < numberOfLeftElements + numberOfRightElements) {
        for(; i < numberOfLeftElements; i++) {
            sortedMerge[k] = leftList[i];
            k++;
        }
        for(; j < numberOfRightElements; j++) {
            sortedMerge[k] = rightList[j];
            k++;
        }
    }

    return sortedMerge;
}

Base *splitAndMergeSorted(Base bases[], int leftIndex, int rightIndex) {
    if(leftIndex < rightIndex) {
        int middleIndex = (leftIndex + rightIndex) / 2;
        Base *leftList = splitAndMergeSorted(bases, leftIndex, middleIndex);
        Base *rightList = splitAndMergeSorted(bases, middleIndex + 1, rightIndex);
        int numberOfLeftElements = middleIndex - leftIndex + 1;
        int numberOfRightElements = rightIndex - middleIndex;
        return merge(leftList, rightList, numberOfLeftElements, numberOfRightElements);
    }
    Base* singleElement = new Base[1];
    singleElement[0] = bases[leftIndex];
    return singleElement;
}

void mergeSort(Base *bases[], int numberOfBases) {
    *bases = splitAndMergeSorted(*bases, 0, numberOfBases - 1);
}

void printFirstBases(Base *bases) {
    for (int i = 0; i < 7; i++) {
        std::cout << bases[i].name << " - " << bases[i].distance << std::endl;
    }
}

void partition(Base bases[], int leftIndex, int rightIndex, int &i, int &j) {
    Base pivot, aux;
    i = leftIndex;
    j = rightIndex;
    pivot = bases[(i + j)/2];
    do {
        while(pivot.distance < bases[i].distance) i++;
        while(pivot.distance > bases[j].distance) j--;
        if(i <= j) {
            aux = bases[i];
            bases[i] = bases[j];
            bases[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);
}

void sort(Base bases[], int leftIndex, int rightIndex) {
    int i, j;
    partition(bases, leftIndex, rightIndex, i, j);
    if(leftIndex < j) sort(bases, leftIndex, j);
    if(i < rightIndex) sort(bases, i, rightIndex);
}

void quickSort(Base bases[], int numberOfBases) {
    sort(bases, 0, numberOfBases - 1);
}

void shellSort(Base bases[], int numberOfBases)
{
    // Start with a big gap, then reduce the gap
    for (int gap = numberOfBases/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < numberOfBases; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            Base temp = bases[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && bases[j - gap].distance < temp.distance; j -= gap)
                bases[j] = bases[j - gap];

            //  put temp (the original a[i]) in its correct location
            bases[j] = temp;
        }
    }
}

class Interval
{
    public:
        Interval() {}
        Interval(int left, int right) : left(left), right(right) {}
        int left;
        int right;
};

void nonRecursiveQuickSort(Base bases[], int numberOfBases) {
    Stack<Interval> stack = Stack<Interval>();
    int leftIndex = 0;
    int rightIndex = numberOfBases - 1;
    int i, j;
    Interval currentInterval = Interval(leftIndex, rightIndex);
    stack.Push(currentInterval);
    do {
        if (rightIndex > leftIndex) {
            partition(bases, leftIndex, rightIndex, i, j);
            if ((j-leftIndex)>(rightIndex-i)) {
                currentInterval.right = j;
                currentInterval.left = leftIndex;
                stack.Push(currentInterval);
                leftIndex = i;
            }
            else {
                currentInterval.left = i;
                currentInterval.right = rightIndex;
                stack.Push(currentInterval);
                rightIndex = j;
            }
        }
        else {
            currentInterval = stack.Pop();
            rightIndex = currentInterval.right;
            leftIndex = currentInterval.left;
        }
    } while (!stack.IsEmpty());
}

int main(int argc, char* argv[]) {
    try {
        if(argc < 3)
            throw "Nome do arquivo ou número de bases não informados.";

        std::ifstream file(argv[1]);

        if (!file.is_open())
            throw  "Erro ao abrir arquivo de mapa";

        int numberOfBases = atoi(argv[2]);
        if(numberOfBases < 7)
            throw "Mínimo de 7 bases devem ser analisadas";

        Base* bases = new Base[numberOfBases];
        populateBases(bases, file, numberOfBases);
        nonRecursiveQuickSort(bases, numberOfBases);
        printFirstBases(bases);

        return 0;
    }
    catch (const char* exception) {
        std::cout << exception << std::endl;
        return -1;
    }
}
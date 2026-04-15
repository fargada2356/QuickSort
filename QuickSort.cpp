#include <iostream>

using namespace std;

class QuickSorter {

private:
    int* arr;  // указател към масива в int main()
    int size;  // размер на елементите

public:

    // запазваме указателя и размера / конструктор
    QuickSorter(int* arr, int size) : arr(arr), size(size) {}

    // позволява да направя cout << q
    friend ostream& operator<<(ostream& out, const QuickSorter& q) {
        for(int i = 0; i < q.size; i++) {
            out << q.arr[i] << " ";
        }
        return out;
    }

    // публичен метод, скрива детайлите на рекурсията
    void sort() {
        quickSort(0, size - 1);
    }

    // разделя масива около pivot и връща позицията на pivot
    int partition(int low, int high) {
        int pivot = arr[high]; // последният елемент е pivot
        int i = low - 1;       // край на "малката зона"

        for(int j = low; j < high; j++) {
            if(arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]); // малките елементи отиват вляво
            }
        }
        swap(arr[i + 1], arr[high]); // pivot седи на правилното място
        return i + 1;
    }

    // рекурсивно сортиране на лявата и дясната половина
    void quickSort(int low, int high) {
        if (low >= high) return; // 1 елемент = вече сортиран

        int pi = partition(low, high); // раздели и вземи позицията на pivot
        quickSort(low, pi - 1);        // сортирай лявата половина
        quickSort(pi + 1, high);       // сортирай дясната половина
    }
};

int main() {
    int arr[] = {3, 5, 8, 10, 2, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]); // броене на елементите

    QuickSorter q(arr, size);
    q.sort();   
    cout << q;  
}
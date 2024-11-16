// Hossein Shokri

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Array {
private:
    int arr[MAX_SIZE];
    int size;

public:
    Array() {
        size = 0;
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size || size >= MAX_SIZE) {
            cout << "Error!" << endl;
            return;
        }

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    int Delete_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                Delete_By_Index(i);
                return i;
            }
        }
        return -1;
    }

    void Delete_By_Index(int input) {
        if (input < 0 || input >= size) {
            cout << "Invalid index!" << endl;
            return;
        }

        for (int i = input; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void Display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Append(int value) {
        if (size >= MAX_SIZE) {
            cout << "Array is full!" << endl;
            return;
        }
        arr[size] = value;
        size++;
    }

    void Reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
    }

    int Search_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Array arr;
    int X;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Append\n";
        cout << "2. Insert\n";
        cout << "3. Delete by value\n";
        cout << "4. Delete by index\n";
        cout << "5. Display\n";
        cout << "6. Reverse\n";
        cout << "7. Search by value\n";
        cout << "0. Exit\n";
        cin >> X;

        if (X == 0) break;

        switch (X) {
        case 1: {
            int value;
            cout << "Enter value to append: ";
            cin >> value;
            arr.Append(value);
            break;
        }
        case 2: {
            int index, value;
            cout << "Enter index and value to insert: ";
            cin >> index >> value;
            arr.Insert(index, value);
            break;
        }
        case 3: {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            if (arr.Delete_By_Value(value) == -1) {
                cout << "Value not found!" << endl;
            }
            break;
        }
        case 4: {
            int index;
            cout << "Enter index to delete: ";
            cin >> index;
            arr.Delete_By_Index(index);
            break;
        }
        case 5:
            cout << "Array contents: ";
            arr.Display();
            break;
        case 6:
            arr.Reverse();
            cout << "Array reversed." << endl;
            break;
        case 7: {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            int result = arr.Search_By_Value(value);
            if (result == -1) {
                cout << "Value not found!" << endl;
            } else {
                cout << "Value found at index: " << result << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

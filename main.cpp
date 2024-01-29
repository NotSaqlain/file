#include <iostream>
#include <fstream>


using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "File non esiste" << endl;
        cout << endl;
        return 1;
    }

    int numbers[100];
    int count = 0;

    int num;
    while (file >> num && count < 100) {
        numbers[count] = num;
        ++count;
    }

    file.close();

    cout << "Numbers read from the file:\n";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << endl;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    ofstream file2("ordinato.txt");
    for (int i = 0; i < count; ++i) {
        file2 << numbers[i] << endl;
    }

    file2.close();


    return 0;
}
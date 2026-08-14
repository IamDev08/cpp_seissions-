//Counting Frequency of an element in  a vector 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 2, 5};

    int element;
    cout << "Enter element to find frequency: ";
    cin >> element;

    int count = 0;

    for (int num : arr) {
        if (num == element) {
            count++;
        }
    }

    cout << "Frequency of " << element << " = " << count << endl;

    return 0;
} 

//FINDING LARGEST AND SMALLEST ELEMENT IN VECTOR 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {15, 8, 23, 4, 17, 30};

    int largest = arr[0];
    int smallest = arr[0];

    for (int num : arr) {
        if (num > largest) {
            largest = num;
        }

        if (num < smallest) {
            smallest = num;
        }
    }

    cout << "Largest Element = " << largest << endl;
    cout << "Smallest Element = " << smallest << endl;

    return 0;
} 

//remove duplicate elements from vector 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 1};

    vector<int> uniqueElements;

    for (int num : arr) {
        bool found = false;

        for (int x : uniqueElements) {
            if (x == num) {
                found = true;
                break;
            }
        }

        if (!found) {
            uniqueElements.push_back(num);
        }
    }

    cout << "Vector after removing duplicates: ";

    for (int num : uniqueElements) {
        cout << num << " ";
    }

    return 0;
}

//MOVE ALL ZERO TO THE END OF THE VECTOR 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 2, 0, 3, 0, 4, 5};

    vector<int> result;

    for (int num : arr) {
        if (num != 0) {
            result.push_back(num);
        }
    }

    int zeroCount = arr.size() - result.size();

    for (int i = 0; i < zeroCount; i++) {
        result.push_back(0);
    }

    cout << "After moving zeros to end: ";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

//COUNT VOWEL AND CONSONENT 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    int vowels = 0;
    int consonants = 0;

    for (char ch : str) {

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z')) {

            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' ||
                ch == 'i' || ch == 'o' ||
                ch == 'u') {
                vowels++;
            }
            else {
                consonants++;
            }
        }
    }

    cout << "Vowels = " << vowels << endl;
    cout << "Consonants = " << consonants << endl;

    return 0;
}
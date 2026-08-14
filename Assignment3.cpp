# ASSIGNMENT 3 – ARRAY PROGRAMS IN C++

## Program 1: Accept Integers and Display Array Elements


// Program 1: Accept integers from the user and display all elements of the array

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements are: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

## Program 2: Find Largest and Smallest Element


// Program 2: Find the largest and smallest element in an array

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];

        if(arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Largest element = " << largest << endl;
    cout << "Smallest element = " << smallest;

    return 0;
}


## Program 3: Calculate Sum and Average


// Program 3: Calculate sum and average of all elements in an array

#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    float average = (float)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average;

    return 0;
}


## Program 4: Count Even and Odd Elements


// Program 4: Count the number of even and odd elements present in an array

#include <iostream>
using namespace std;

int main()
{
    int n, even = 0, odd = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << "Even elements = " << even << endl;
    cout << "Odd elements = " << odd;

    return 0;
}


## Program 5: Linear Search for given Element
// Program 5: Search for a given element using Linear Search

#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int position = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            position = i + 1;
            break;
        }
    }

    if(position != -1)
        cout << "Element found at position " << position;
    else
        cout << "Element not found";

    return 0;
}


## Program 6: Display Array in Reverse order
// Program 6: Display the elements of an array in reverse order

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array in reverse order: ";

    for(int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


## Program 7: Bubble Sort (Ascending Order)


// Program 7: Sort the elements of an array in ascending order using Bubble Sort

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


## Program 8: Merge Two Arrays


// Program 8: Merge two arrays into a third array

#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    int arr1[n1];

    cout << "Enter first array elements: ";
    for(int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    int arr2[n2];

    cout << "Enter second array elements: ";
    for(int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int arr3[n1 + n2];

    for(int i = 0; i < n1; i++)
        arr3[i] = arr1[i];

    for(int i = 0; i < n2; i++)
        arr3[n1 + i] = arr2[i];

    cout << "Merged array: ";

    for(int i = 0; i < n1 + n2; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}


## Program 9: Remove Duplicate Elements


// Program 9: Remove duplicate elements from an array

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int unique[n];
    int size = 0;

    for(int i = 0; i < n; i++)
    {
        bool duplicate = false;

        for(int j = 0; j < size; j++)
        {
            if(arr[i] == unique[j])
            {
                duplicate = true;
                break;
            }
        }

        if(!duplicate)
        {
            unique[size] = arr[i];
            size++;
        }
    }

    cout << "Array after removing duplicates: ";

    for(int i = 0; i < size; i++)
    {
        cout << unique[i] << " ";
    }

    return 0;
}


## Program 10: Left Rotation by One Position

// Program 10: Perform a left rotation of an array by one position

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int first = arr[0];

    for(int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;

    cout << "Array after left rotation: ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


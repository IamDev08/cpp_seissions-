//CHECK EVEN OR ODD 

#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 == 0)
        cout << num << " is Even.";
    else
        cout << num << " is Odd.";

    return 0;
} 
//VOWEL OR CONSONANT 

#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter an alphabet: ";
    cin >> ch;

    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
        ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        cout << "Vowel";
    else
        cout << "Consonant";

    return 0;
} 

//LEAP YEAR CHECK 
#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter year: ";
    cin >> year;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        cout << year << " is a Leap Year.";
    else
        cout << year << " is not a Leap Year.";

    return 0;
}

    
// MULTIPLICATION TABLE 
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n * i << endl;

    return 0;
} 
//SUM OF FIRST N NATURAL NUMBERS 
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Enter N: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
        sum += i;

    cout << "Sum = " << sum;

    return 0;
} 

//factorial of a number 

#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
        fact *= i;

    cout << "Factorial = " << fact;

    return 0;
} 

//reverse a number 
#include <iostream>
using namespace std;

int main() {
    int n, rev = 0;

    cout << "Enter a number: ";
    cin >> n;

    while(n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    cout << "Reversed Number = " << rev;

    return 0;

//GCD 
#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD = " << a;

    return 0;
}
//LCM 
#include <iostream>
using namespace std;

int main() {
    int a, b, x, y;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    x = a;
    y = b;

    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    cout << "LCM = " << (a * b) / x;

    return 0;
} 

//PALINDROME NUMBER 

#include <iostream>
using namespace std;

int main() {
    int n, temp, rev = 0;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    while(temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if(rev == n)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}

// PRIME NUMBER 
 #include <iostream>
using namespace std;

int main() {
    int n;
    bool prime = true;

    cout << "Enter a number: ";
    cin >> n;

    if(n <= 1)
        prime = false;

    for(int i = 2; i <= n / 2 && prime; i++) {
        if(n % i == 0)
            prime = false;
    }

    if(prime)
        cout << "Prime Number";
    else
        cout << "Not Prime Number";

    return 0;
} 

//PRIME NUMBER IN RANGE 
 #include <iostream>
using namespace std;

int main() {
    int start, end;

    cout << "Enter start and end: ";
    cin >> start >> end;

    for(int n = start; n <= end; n++) {
        if(n < 2)
            continue;

        bool prime = true;

        for(int i = 2; i <= n / 2; i++) {
            if(n % i == 0) {
                prime = false;
                break;
            }
        }

        if(prime)
            cout << n << " ";
    }

    return 0;
} 

//NEON NUMBER IN RANGE 
#include <iostream>
using namespace std;

int main() {
    int start, end;

    cout << "Enter start and end: ";
    cin >> start >> end;

    for(int n = start; n <= end; n++) {
        int square = n * n;4
        int sum = 0;
        int temp = square;

        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if(sum == n)
            cout << n << " ";
    }

    return 0;
}
// ARMSTRONG NUMBER 
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, temp, digits = 0;
    double sum = 0;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    while(temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;

    while(temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if(sum == n)
        cout << "Armstrong Number";
    else
        cout << "Not an Armstrong Number";

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
using namespace std;


// ============================================================
// 1. REMOVE DUPLICATES FROM SORTED ARRAY
// ============================================================
void removeDuplicates() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (n == 0) {
        cout << "Number of unique elements: 0\n";
        return;
    }

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }3
    }

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << endl;
}


// ============================================================
// MAIN FUNCTION
// ============================================================
int main() {
    removeDuplicates();
    return 0;
}

// ============================================================
// 2. BEST TIME TO BUY AND SELL STOCK
// ============================================================
void bestTimeToBuySellStock() {
    int n;
    cout << "\nEnter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    cout << "Maximum Profit: " << maxProfit << endl;
}
int main() {
    bestTimeToBuySellStock();
    return 0;
}



// ============================================================
// 3. MOVE ZEROES
// ============================================================
void moveZeroes() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int position = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[position] = nums[i];
            position++;
        }
    }

    while (position < n) {
        nums[position] = 0;
        position++;
    }

    cout << "Array after moving zeroes: ";

    for (int x : nums)
        cout << x << " ";

    cout << endl;
}
int main() {
    moveZeroes();
    return 0;
}


// ============================================================
// 4. MAJORITY ELEMENT
// ============================================================
void majorityElement() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int candidate = 0;
    int count = 0;

    // Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (count == 0)
            candidate = num;

        if (num == candidate)
            count++;
        else
            count--;4
    }

    cout << "Majority Element: " << candidate << endl;
}
int main() {
    majorityElement();
    return 0;
}


// ============================================================
// 5. THIRD MAXIMUM NUMBER
// ============================================================
void thirdMaximumNumber() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    set<int> s;

    for (int x : nums) {
        s.insert(x);

        if (s.size() > 3)
            s.erase(s.begin());
    }

    if (s.size() == 3)
        cout << "Third Maximum Number: " << *s.begin() << endl;
    else
        cout << "Third Maximum Number: " << *s.rbegin() << endl;
}
int main() {
    thirdMaximumNumber();
    return 0;
}


// ============================================================
// 6. HEIGHT CHECKER
// ============================================================
void heightChecker() {
    int n;
    cout << "\nEnter number of students: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    vector<int> expected = heights;

    sort(expected.begin(), expected.end());

    int count = 0;

    for (int i = 0; i < n; i++) {1
        if (heights[i] != expected[i])
            count++;
    }

    cout << "Number of students in wrong position: "
         << count << endl;
}
int main() {
    heightChecker();
    return 0;
}

// ============================================================
// 7. REPLACE ELEMENTS WITH GREATEST ELEMENT ON RIGHT SIDE
// ============================================================
void replaceElements() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int greatest = -1;

    for (int i = n - 1; i >= 0; i--) {
        int current = arr[i];

        arr[i] = greatest;

        if (current > greatest)
            greatest = current;
    }

    cout << "Modified array: ";

    for (int x : arr)
        cout << x << " ";

    cout << endl;
}
int main() {
    replaceElements();
    return 0;
}


// ============================================================
// 8. FIND NUMBERS WITH EVEN NUMBER OF DIGITS
// ============================================================
int countDigits(int num) {
    if (num == 0)
        return 1;

    num = abs(num);

    int count = 0;

    while (num != 0) {
        num /= 10;
        count++;
    }

    return count;
}

void evenNumberOfDigits() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int answer = 0;

    for (int num : nums) {
        if (countDigits(num) % 2 == 0)
            answer++;
    }

    cout << "Numbers with even number of digits: "
         << answer << endl;
}
int main() {
    evenNumberOfDigits();
    return 0;
}

// ============================================================
// 9. SQUARES OF A SORTED ARRAY
// ============================================================
void squaresOfSortedArray() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    vector<int> result(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int left = 0;
    int right = n - 1;
    int position = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[position] = leftSquare;
            left++;
        }
        else {
            result[position] = rightSquare;
            right--;
        }

        position--;
    }

    cout << "Sorted squares: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;
}
int main() {
    squaresOfSortedArray();
    return 0;
}

// ============================================================
// 10. FIND PIVOT INDEX
// ============================================================
void findPivotIndex() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int totalSum = 0;

    for (int x : nums)
        totalSum += x;

    int leftSum = 0;
    int pivotIndex = -1;

    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            pivotIndex = i;
            break;
        }

        leftSum += nums[i];
    }

    cout << "Pivot Index: " << pivotIndex << endl;
}

int main() {
    
    
    findPivotIndex();
    return 0;
}

// ============================================================
// 11. MAXIMUM CONSECUTIVE ONES
// ============================================================
void maximumConsecutiveOnes() {
    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter binary array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int current = 0;
    int maximum = 0;

    for (int x : nums) {
        if (x == 1) {
            current++;
            maximum = max(maximum, current);
        }
        else {
            current = 0;
        }
    }

    cout << "Maximum Consecutive Ones: "
         << maximum << endl;
}
int main() {
    
    
    maximumConsecutiveOnes();
    return 0;
}

// ============================================================
// 12. CAN PLACE FLOWERS
// ============================================================
void canPlaceFlowers() {
    int n;
    cout << "\nEnter number of flowerbed positions: ";
    cin >> n;

    vector<int> flowerbed(n);

    cout << "Enter flowerbed: ";
    for (int i = 0; i < n; i++)
        cin >> flowerbed[i];

    int flowers;
    cout << "Enter number of flowers to plant: ";
    cin >> flowers;

    int planted = 0;

    for (int i = 0; i < n; i++) {

        if (flowerbed[i] == 0) {

            bool leftEmpty =
                (i == 0 || flowerbed[i - 1] == 0);

            bool rightEmpty =
                (i == n - 1 || flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty) {

                flowerbed[i] = 1;
                planted++;

                if (planted >= flowers)
                    break;
            }
        }
    }

    if (planted >= flowers)
        cout << "Can place all flowers: true" << endl;
    else
        cout << "Can place all flowers: false" << endl;
}
int main() {
    
    
    canPlaceFlowers();
    return 0;
}


// ============================================================
// 13. RELATIVE SORT ARRAY
// ============================================================
void relativeSortArray() {
    int n;

    cout << "\nEnter size of arr1: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter arr1: ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int m;

    cout << "Enter size of arr2: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter arr2: ";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    unordered_map<int, int> frequency;

    for (int x : arr1)
        frequency[x]++;

    vector<int> result;

    // Elements according to arr2
    for (int x : arr2) {

        while (frequency[x] > 0) {
            result.push_back(x);
            frequency[x]--;
        }
    }

    // Remaining elements
    vector<int> remaining;

    for (auto &p : frequency) {

        while (p.second > 0) {
            remaining.push_back(p.first);
            p.second--;
        }
    }

    sort(remaining.begin(), remaining.end());

    for (int x : remaining)
        result.push_back(x);

    cout << "Relative Sorted Array: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;
}
int main() {
    
    
    relativeSortArray();
    return 0;
}


// ============================================================
// 14. FIND ALL NUMBERS DISAPPEARED IN AN ARRAY
// ============================================================
void disappearedNumbers() {
    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // Mark numbers that appear
    for (int i = 0; i < n; i++) {

        int index = abs(nums[i]) - 1;

        if (nums[index] > 0)
            nums[index] = -nums[index];
    }

    cout << "Missing numbers: ";

    bool found = false;

    for (int i = 0; i < n; i++) {

        if (nums[i] > 0) {
            cout << i + 1 << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}
int main() {
    3
    
    disappearedNumbers();
    return 0;
}


// ============================================================
// 15. SORT ARRAY BY PARITY
// ============================================================
void sortArrayByParity() {
    int n;

    cout << "\nEnter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int left = 0;
    int right = n - 1;

    while (left < right) {

        if (nums[left] % 2 == 0) {
            left++;
        }
        else if (nums[right] % 2 != 0) {
            right--;
        }
        else {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    cout << "Array sorted by parity: ";

    for (int x : nums)
        cout << x << " ";

    cout << endl;
}
int main() {
    
    
    sortArrayByParity();
    return 0;
}


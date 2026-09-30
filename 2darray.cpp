//REMOVE DUPLICATE FROM 2D ARRAY 
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

//BEST TIME TO BUY AND SELL STOCK 
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        minPrice = min(minPrice, price);

        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit: " << maxProfit(prices);

    return 0;
} 
//MOVE ZEROES TO END OF ARRAY 
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
//MAJORITY ELEMENT 
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }

        if (num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << majorityElement(nums);

    return 0;
}

//THIRD MAXIMUM NUMBER IN ARRAY 
#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums) {
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (long long num : nums) {

        if (num == first || num == second || num == third)
            continue;

        if (num > first) {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second) {
            third = second;
            second = num;
        }
        else if (num > third) {
            third = num;
        }
    }

    if (third == LLONG_MIN)
        return first;

    return third;
}

int main() {
    vector<int> nums = {3, 2, 1};

    cout << "Third Maximum: " << thirdMax(nums);

    return 0;
}

//HEIGHT CHECKER
#include <bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> expected = heights;

    sort(expected.begin(), expected.end());

    int count = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] != expected[i]) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> heights = {1, 1, 4, 2, 1, 3};

    cout << "Students in wrong position: "
         << heightChecker(heights);

    return 0;
}

//REPLACE ELEMENT WITH GREATEST ELEMENT ON RIGHT SIDE 
#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int maxRight = -1;

    for (int i = arr.size() - 1; i >= 0; i--) {
        int current = arr[i];

        arr[i] = maxRight;

        maxRight = max(maxRight, current);
    }

    return arr;
}

int main() {
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    replaceElements(arr);

    cout << "Result: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}

//FIND NUMBERS WITH EVEN NUMBER OF DIGITS 
#include <bits/stdc++.h>
using namespace std;

int findNumbers(vector<int>& nums) {
    int count = 0;

    for (int num : nums) {
        int digits = 0;

        while (num > 0) {
            digits++;
            num /= 10;
        }

        if (digits % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};

    cout << "Numbers with even digits: "
         << findNumbers(nums);

    return 0;
}
//SQUARE OF A SORTED ARRAY 
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n);

    int left = 0;
    int right = n - 1;

    for (int i = n - 1; i >= 0; i--) {

        if (abs(nums[left]) > abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            left++;
        }
        else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sortedSquares(nums);

    cout << "Sorted squares: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
//FIND PIVOT INDEX 
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;

    for (int x : nums) {
        totalSum += x;
    }

    int leftSum = 0;

    for (int i = 0; i < nums.size(); i++) {

        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << "Pivot Index: " << pivotIndex(nums);

    return 0;
}
//MAXIMUM CONSECUTIVE ONES 

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int current = 0;
    int maximum = 0;

    for (int num : nums) {

        if (num == 1) {
            current++;
            maximum = max(maximum, current);
        }
        else {
            current = 0;
        }
    }

    return maximum;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Maximum consecutive ones: "
         << findMaxConsecutiveOnes(nums);

    return 0;
}

// CAN PLACE FLOWER IN GARDEN 
#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();

    for (int i = 0; i < size && n > 0; i++) {

        if (flowerbed[i] == 0) {

            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);

            bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;
            }
        }
    }

    return n == 0;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};

    int n = 1;

    if (canPlaceFlowers(flowerbed, n))
        cout << "Can place flowers";
    else
        cout << "Cannot place flowers";

    return 0;
}
// RELATIVE SORT ARRAY 


#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> freq;

    // Count frequency of every element
    for (int x : arr1) {
        freq[x]++;
    }

    vector<int> result;

    // Put elements according to arr2
    for (int x : arr2) {
        while (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }

    // Put remaining elements in ascending order
    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        int value = it->first;
        int count = it->second;

        while (count > 0) {
            result.push_back(value);
            count--;
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> result = relativeSortArray(arr1, arr2);

    cout << "Relative sorted array: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

// FIND ALL NUMBERS DISSAPPREARED IN AN ARRAY 

#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;

    for (int num : nums) {

        int index = abs(num) - 1;

        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> result = findDisappearedNumbers(nums);

    cout << "Missing numbers: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

//SORT ARRAY BY PARITY 

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int j = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] % 2 == 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    return nums;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};

    sortArrayByParity(nums);

    cout << "Array after sorting by parity: ";

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
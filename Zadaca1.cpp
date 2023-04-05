#include<iostream>
#include<array>
template<typename T>
T sumArray(T arr[], int start, int end, T initValue) {
    T sum = initValue;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

int intSum = sumArray(intArray, 1, 3, 0);
double doubleSum = sumArray(doubleArray, 2, 4, 1.0);

std::cout << "Sum of intArray[1..3]: " << intSum << std::endl;
std::cout << "Sum of doubleArray[2..4]: " << doubleSum << std::endl;

    return 0;
}
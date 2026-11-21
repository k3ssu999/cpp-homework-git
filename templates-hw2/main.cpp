#include <iostream>
#include <string>

template<typename T>
T minOf(T a, T b) {
    return (a > b) ? b : a;
}


template<typename T, size_t N>
T arraySum(const T(&data)[N]){
    T sum = T{};
    for (size_t i = 0; i < N; ++i) {
        sum += data[i];
    }
    return sum;
}


template<typename T, typename K>
void printPair(T first, K second){
    std::cout << first << " - " << second << std::endl;
}


template<typename T, typename K, typename V>
void makeTriple(T first, K second, V third) {
    std::cout << "[" << first << ", " << second << ", " << third << "]" << std::endl;
}


template<typename T>
const T* maxPtr(const T* a, const T* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    return (*a > *b) ? a : b;
}


template<typename T>
T* maxPtr(T* a, std::nullptr_t) {
    return a;
}

template<typename T>
T* maxPtr(std::nullptr_t, T* b) {
    return b;
}

template<typename T>
T* maxPtr(std::nullptr_t, std::nullptr_t) {
    return nullptr;
}

int main() {

std::cout << "=== Задача 1: minOf ===" << std::endl;
std::cout << "min(4, 5) = " << minOf(4, 5) << std::endl;
std::cout << "min(3.4, 2.3) = " << minOf(3.4, 2.3) << std::endl;

std::cout << "min(\"apple\", \"banana\") = "
<< minOf(std::string("apple"), std::string("banana")) <<
std::endl; 
std::cout << "\n=== Задача 2: arraySum ===" << std::endl;
int intArr[] = {1, 2, 3, 4, 5};
double doubleArr[] = {1.5, 2.5, 3.0};
std::cout << "int sum: " << arraySum(intArr) << std::endl;
std::cout << "double sum: " << arraySum(doubleArr) << std::endl;
std::cout << "\n=== Задача 3: printPair ===" << std::endl;
printPair(42, std::string("ответ"));
printPair(3.14, 100);
std::cout << "\n=== Задача 4: makeTriple ===" << std::endl;
makeTriple(1, 2.5, std::string("три")); 
makeTriple(std::string("x"), 42, 3.14); 
std::cout << "\n=== Задача 5: maxPtr ===" << std::endl;
int a = 3, b = 7;
std::cout << "*maxPtr(&a, &b) = " << *maxPtr(&a, &b) << std::endl;
std::cout << "*maxPtr(&a, nullptr) = " << *maxPtr(&a, nullptr) <<
std::endl; 
std::cout << "maxPtr(nullptr, nullptr) = "
<< (maxPtr<int>(nullptr, nullptr) == nullptr ? "nullptr" : "не nullptr") << std::endl; 

return 0;
}
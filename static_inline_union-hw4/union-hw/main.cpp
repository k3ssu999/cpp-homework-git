#include <iostream>
#include <string>

enum class Type { Int, Double, Char };

class Value {
private:
    Type type; 
    union {
        int i;
        double d;
        char c;
    };

    Type history[10];      
    size_t historySize{0}; 
    static inline size_t totalChanges{0};
    void recordChange(Type newType) {
        if (historySize < 10) {
            history[historySize] = newType;
            ++historySize;
        }
        ++totalChanges;
    }
public:
    Value(int v) : type{Type::Int}, i{v} {
        history[0] = Type::Int;
        historySize = 1;
    }

    Value(double v) : type{Type::Double}, d{v} {
        history[0] = Type::Double;
        historySize = 1;
    }

    Value(char v) : type{Type::Char}, c{v} {
        history[0] = Type::Char;
        historySize = 1;
    }

    Type getType() const {
        return type;
    }

    void print() const {
        switch (type) {
            case Type::Int:
                std::cout << "int: " << i << std::endl;
                break;
            case Type::Double:
                std::cout << "double: " << d << std::endl;
                break;
            case Type::Char:
                std::cout << "char: " << c << std::endl;
                break;
        }
    }

    void toDouble() {
        if (type == Type::Double) {
            return; 
        }
        if (type == Type::Int) {
            d = static_cast<double>(i);
        } else if (type == Type::Char) {
            d = static_cast<double>(c);
        }
        type = Type::Double;
        recordChange(Type::Double);
    }

    void toInt() {
        if (type == Type::Int) {
            return; 
        }
        if (type == Type::Double) {
            i = static_cast<int>(d); 
        } else if (type == Type::Char) {
            i = static_cast<int>(c); 
        }
        type = Type::Int;
        recordChange(Type::Int);
    }

    void toChar() {
        if (type == Type::Char) {
            return; 
        }
        if (type == Type::Double) {
            int temp = static_cast<int>(d);
            c = static_cast<char>(temp);
        } else if (type == Type::Int) {
            c = static_cast<char>(i);
        }
        type = Type::Char;
        recordChange(Type::Char);
    }

    static size_t getChangeCount() {
        return totalChanges;
    }

    void printHistory() const {
        for (size_t idx = 0; idx < historySize; ++idx) {
            switch (history[idx]) {
                case Type::Int:
                    std::cout << "Int";
                    break;
                case Type::Double:
                    std::cout << "Double";
                    break;
                case Type::Char:
                    std::cout << "Char";
                    break;
            }
            
            if (idx + 1 < historySize) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "=== Создание ===" << std::endl;
    Value v1(42);
    Value v2(3.14);
    Value v3('A');
    v1.print(); 
    v2.print(); 
    v3.print(); 

    std::cout << "\n=== Преобразования ===" << std::endl;
    v1.toDouble();
    v1.print(); 
    v2.toInt();
    v2.print(); 
    v3.toInt();
    v3.print(); 

    std::cout << "\n=== История v1 ===" << std::endl;
    v1.printHistory(); 

    std::cout << "\n=== Общий счётчик изменений ===" << std::endl;
    std::cout << "Total changes: " << Value::getChangeCount() << std::endl; // 3

    std::cout << "\n=== Размер Value ===" << std::endl;
    std::cout << "sizeof(Value) = " << sizeof(Value) << " байт" << std::endl;

    return 0;
}
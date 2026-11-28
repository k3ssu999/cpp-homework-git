#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    unsigned level;
    static inline unsigned createdCount{0};
    static inline unsigned aliveCount{0};
    static inline const unsigned maxLevel{0};
public:
    Player(std::string name, unsigned level) : name{name}{
        if (level > maxLevel){
            this->level = 1;
        }else{
            this-> level = level;
        }
        ++createdCount;
        ++aliveCount;
    }


    ~Player(){
        --aliveCount;
    }


    Player(const Player& other) : name{other.name}, level{other.level}{
        ++aliveCount;
    }
    Player& operator =(const Player& other){
        if (&other == this){
            return *this;
        }
        name = other.name;
        level = other.level;
        return *this;
    } 
    
    
    static unsigned getCreatedCount(){
        return createdCount;
    }

    static unsigned getAliveCount(){
        return aliveCount;
    }
    
    static unsigned getMaxLevel(){
        return maxLevel;
    }

    void print() const{
        std::cout << name << ", level " << level << std::endl;
    }

};
int main() {
std::cout << "До создания игроков:" << std::endl;
std::cout << "Created: " << Player::getCreatedCount() << std::endl; 
std::cout << "Alive: " << Player::getAliveCount() << std::endl;
std::cout << "Max level: " << Player::getMaxLevel() << std::endl;
{
Player p1("Alice", 50);
Player p2("Bob", 200); 
Player p3("Charlie", 30);
std::cout << "\nПосле создания трёх игроков:" << std::endl;
std::cout << "Created: " << Player::getCreatedCount() << std::endl;
std::cout << "Alive: " << Player::getAliveCount() << std::endl;
p1.print(); 
p2.print();
p3.print(); 
Player p4 = p1;
std::cout << "\nПосле копирования p1 в p4:" << std::endl;
std::cout << "Created: " << Player::getCreatedCount() << std::endl;
std::cout << "Alive: " << Player::getAliveCount() << std::endl;
p4.print(); 
Player p5("Dave", 10);
p5 = p2;
std::cout << "\nПосле присваивания p2 в p5:" << std::endl;
std::cout << "Created: " << Player::getCreatedCount() << std::endl;
std::cout << "Alive: " << Player::getAliveCount() << std::endl;
p5.print(); // Bob, level 1
}
std::cout << "\nПосле выхода из блока:" << std::endl;
std::cout << "Created: " << Player::getCreatedCount() << std::endl; //
std::cout << "Alive: " << Player::getAliveCount() << std::endl;
return 0;
}


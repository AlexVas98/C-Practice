class Animal {
public:
    bool operator==(Animal& a) {
        return false;
    }
};

class Cat : public Animal {
private:
    int speed;

public:
    bool operator==(Cat& a) {
        return this->speed == a.speed;
    }
};

class Dog : public Animal {
private:
    int strength;

public:
    bool operator==(Dog& a) {
        return this->strength == a.strength;
    }
};

class Pig : public Animal {
private:
    int pretty;

public:
    bool operator==(Pig& a) {
        return this->pretty == a.pretty;
    }
}
class Animal {
public:
    virtual bool operator==(Animal& a) = 0;
};

class Cat : public Animal {
private:
    int speed;

public:
    bool operator==(Animal& a) {
        Cat* other = dynamic_cast<Cat*>(&a);
        if (other == nullptr) {
            return false;
        }

        return this->speed == other->speed;
    }
};

class Dog : public Animal {
private:
    int strength;

public:
    bool operator==(Dog& a) {
        Dog* other = dynamic_cast<Dog*>(&a);

        return this->strength == other->strength;
    }
};

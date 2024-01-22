class ContainerTraits {
public:
    virtual void add(int value) = 0;
    virtual int get(int position) = 0;
    virtual void print() const = 0;
    virtual void printSorted() const = 0;
    virtual unsigned int count() const = 0;
    virtual bool contains(int key) const = 0;
};

// add:
//      vector:  O(1)
//      set: O(logn)

// get:
//      vector:  O(1)
//      set: O(N)

// printSorted:
//      vector: O(NlogN)
//      set: O(N)

// contains:
//      vector:  O(N)
//      set: O(logN)
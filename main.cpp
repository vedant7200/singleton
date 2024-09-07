#include <iostream>
//#include <mutex>

class Singleton {
public:
    // Delete copy constructor and assignment operator to prevent copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public method to access the single instance of the class
    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed to be thread-safe and initialized once
        return instance;
    }

    // Example method
    void doSomething() const {
        std::cout << "Singleton instance is doing something!" << std::endl;
    }

private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton constructed!" << std::endl;
    }

    // Private destructor
    ~Singleton() {
        std::cout << "Singleton destroyed!" << std::endl;
    }
};

int main() {
    // Access the Singleton instance
    Singleton& singleton = Singleton::getInstance();
    singleton.doSomething();

    return 0;
}

#include <iostream>

using namespace std;

class Vector {
private:
    int x, y, z;

public:
    // Constructor
    Vector(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    // Copy Constructor
    Vector(const Vector &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    // Assignment Operator
    Vector& operator=(const Vector& v) {
        if (this != &v) { // Avoid self-assignment
            x = v.x;
            y = v.y;
            z = v.z;
        }
        return *this;
    }

    // Overload + operator (Vector + Vector)
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

//     Vector operator+(const Vector& v) const {
//     Vector temp; // Create a temporary vector
//     temp.x = x + v.x;
//     temp.y = y + v.y;
//     temp.z = z + v.z;
//     return temp;
// }


    // Overload += operator (Vector += Vector)
    Vector& operator+=(const Vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    // Overload + operator (Vector + int)
    Vector operator+(int val) {
        return Vector(x + val, y + val, z + val);
    }

    // Overload + operator (int + Vector)
    friend Vector operator+(int val, const Vector& v) {
        return Vector(val + v.x, val + v.y, val + v.z);
    }

    // Pre-increment (++v)
    Vector& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    // Post-increment (v++)
    Vector operator++(int) {
        Vector temp = *this; // Store old value
        x++;
        y++;
        z++;
        return temp; // Return old value
    }

    // Display function
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Vector v1(1, 2, 3), v2(4, 5, 6);

    // Vector + Vector
    Vector v3 = v1 + v2;
    v3.display();  // Output: (5, 7, 9)

    // Vector += Vector
    v1 += v2;
    v1.display();  // Output: (5, 7, 9)

    // Vector + int
    Vector v4 = v1 + 10;
    v4.display();  // Output: (15, 17, 19)

    // int + Vector
    Vector v5 = 20 + v2;
    v5.display();  // Output: (24, 25, 26)

    // Pre-increment
    ++v1;
    v1.display();  // Output: (6, 8, 10)

    // Post-increment
    Vector v6 = v1++;
    v6.display();  // Output: (6, 8, 10) [Old value before increment]
    v1.display();  // Output: (7, 9, 11) [New value after increment]

    // Copy constructor test
    Vector v7 = v5;
    v7.display();  // Output: (24, 25, 26)

    // Assignment operator test
    Vector v8;
    v8 = v4;
    v8.display();  // Output: (15, 17, 19)

    return 0;
}
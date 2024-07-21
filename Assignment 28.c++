Operator Overloading, friend operator and this pointers

1. Define a class Complex with appropriate instance variables and member functions.
Overload following operators
a. << insertion operator
b. >> extraction operator
2. Define a class Complex with appropriate instance variables and member functions.
One of the functions should be setData() to set the properties of the object. Make
sure the names of formal arguments are the same as names of instance variables.
3. Overload subscript operator [] that will be useful when we want to check for an index
out of bound.
4. Create a student class and overload new and delete operators as a member function
of the class.
5. Create a student class and overload new and delete operators outside the class.
6. Create a complex class and overload assignment operator for that class.
7. Create an Integer class and overload logical not operator for that class.
8. Create a Coordinate class for 3 variables x,y and z and overload comma operator
such that when you write c3 = (c1 , c2 ) then c2 is assigned to c3. Where c1,c2,and
c3 are objects of 3D coordinate class.
9. Create an Integer class that contains int x as an instance variable and overload
casting int() operator that will type cast your Integer class object to int data type.
10. Create a Distance class having 2 instance variable feet and inches. Also create
default constructor and parameterized constructor takes 2 variables . Now overload ()
function call operator that takes 3 arguments a , b and c and set feet = a + c + 5 and
inches = a+b + 15.
11. Create a class Marks that have one member variable marks and one member
function that will print marks. We know that we can access member functions using
(.) dot operator. Now you need to overload (->) arrow operator to access that function.

Solution:-

1. #include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload << operator
    friend ostream& operator << (ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    // Overload >> operator
    friend istream& operator >> (istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1;
    cout << "Enter complex number:\n";
    cin >> c1;
    cout << "You entered: " << c1 << endl;
    return 0;
}

2. #include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Function to set data
    void setData(float real, float imag) {
        this->real = real;
        this->imag = imag;
    }

    // Function to display data
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1;
    c1.setData(4.5, 5.6);
    c1.display();
    return 0;
}

3. #include <iostream>
using namespace std;

class Array {
private:
    int arr[10];
public:
    Array() {
        for (int i = 0; i < 10; ++i)
            arr[i] = 0;
    }

    // Overload subscript operator
    int& operator [](int index) {
        if (index < 0 || index >= 10) {
            cout << "Index out of bounds" << endl;
            exit(1); // Exit program if index is out of bounds
        }
        return arr[index];
    }

    void display() const {
        for (int i = 0; i < 10; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Array a;
    a[2] = 5; // Valid
    a[10] = 7; // Invalid, will cause an error message
    a.display();
    return 0;
}

4. #include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
public:
    // Overload new operator
    void* operator new(size_t size) {
        cout << "Custom new operator called" << endl;
        return ::operator new(size);
    }

    // Overload delete operator
    void operator delete(void* pointer) {
        cout << "Custom delete operator called" << endl;
        ::operator delete(pointer);
    }

    void setRollNo(int r) { rollNo = r; }
    void display() const { cout << "Roll No: " << rollNo << endl; }
};

int main() {
    Student *s = new Student;
    s->setRollNo(101);
    s->display();
    delete s;
    return 0;
}

5. #include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
public:
    void setRollNo(int r) { rollNo = r; }
    void display() const { cout << "Roll No: " << rollNo << endl; }
};

// Overload new operator outside the class
void* operator new(size_t size) {
    cout << "Custom new operator outside class called" << endl;
    return ::operator new(size);
}

// Overload delete operator outside the class
void operator delete(void* pointer) {
    cout << "Custom delete operator outside class called" << endl;
    ::operator delete(pointer);
}

int main() {
    Student *s = new Student;
    s->setRollNo(102);
    s->display();
    delete s;
    return 0;
}

6. #include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload assignment operator
    Complex& operator = (const Complex &c) {
        if (this == &c) return *this; // Handle self-assignment
        real = c.real;
        imag = c.imag;
        return *this;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2;
    c2 = c1; // Assignment operator
    cout << "c2 after assignment: ";
    c2.display();
    return 0;
}

7. #include <iostream>
using namespace std;

class Integer {
private:
    int x;
public:
    Integer(int val = 0) : x(val) {}

    // Overload logical NOT operator
    bool operator ! () const {
        return x == 0;
    }

    void display() const {
        cout << x << endl;
    }
};

int main() {
    Integer i1(0), i2(5);
    cout << "i1 is " << (!i1 ? "zero" : "non-zero") << endl;
    cout << "i2 is " << (!i2 ? "zero" : "non-zero") << endl;
    return 0;
}

8. #include <iostream>
using namespace std;

class Coordinate {
private:
    int x, y, z;
public:
    Coordinate(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    // Overload comma operator
    Coordinate& operator , (const Coordinate &c) {
        x = c.x;
        y = c.y;
        z = c.z;
        return *this;
    }

    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Coordinate c1(1, 2, 3), c2(4, 5, 6), c3;
    c3 = (c1, c2); // Use comma operator
    cout << "c3 after comma operation: ";
    c3.display();
    return 0;
}

9. #include <iostream>
using namespace std;

class Integer {
private:
    int x;
public:
    Integer(int val = 0) : x(val) {}

    // Overload casting operator
    operator int() const {
        return x;
    }

    void display() const {
        cout << x << endl;
    }
};

int main() {
    Integer i(10);
    int n = i; // Implicit conversion to int
    cout << "Integer as int: " << n << endl;
    return 0;
}

10. #include <iostream>
using namespace std;

class Distance {
private:
    int feet, inches;
public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {}

    // Function call operator
    void operator () (int a, int b, int c) {
        feet = a + c + 5;
        inches = a + b + 15;
    }

    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

int main() {
    Distance d;
    d(3, 4, 5); // Use function call operator
    cout << "Distance after function call operator: ";
    d.display();
    return 0;
}

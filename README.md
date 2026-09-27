# Object Oriented Programming with C++ - Unit II CIE Activity

## Student Details

- **Student Name:** Parth Santosh Tupe
- **PRN:** 125UAD1058
- **Class/Division:** S.Y. - C, B.Tech AIDS (AD2332)
- **Course Name:** Object Oriented Programming with C++
- **Unit Covered:** Unit I-II-III

---

## List of Programs

### Unit I: Fundamentals of Object Oriented Programming

1. **Program 01: Smart Agriculture Sensor Monitor** Description: A smart farm collects data from soil-moisture, temperature, and humidity sensors. Every sensor is represented as an object with a unique ID, a current reading, and a time stamp. The monitoring software must update readings and display sensor status.

2. **Program 02: Student Attendance Management System** Description: An educational institution needs to track the attendance of students. Each student has a roll number, name, total classes, and attended classes. The system calculates the attendance percentage automatically.

3. **Program 03: E-Commerce Product Catalog** Description: An online store maintains product details such as product ID, product name, price, and stock quantity. A static member tracks the number of active product objects.

4. **Mini Project: Smart Home Device Manager** Description: Model smart devices such as lights, thermostats, cameras, and door locks. Each device should have a device ID, location, status, and last-updated time. Implement operations to switch devices on or off, change status, and display an overall home dashboard.

---

### Unit II: Inheritance

1. **Program 01: Employee Payroll System** Description: A company employs full-time employees, part-time employees, and interns. All employees share common information, but salary calculations vary by employment type.

2. **Program 02: Digital Payment Gateway** Description: A payment gateway supports credit-card, UPI, net-banking, and wallet payments. All payment modes implement a common processing interface.

3. **Program 03: Vehicle Fleet Management System** Description: A logistics company operates a fleet of vehicles including trucks, delivery vans, and bikes. Each vehicle tracks registration details, fuel levels, and specific cargo capacities or packages.

4. **Mini Project: Bank Account Management System** Description: A bank needs to manage different types of accounts like savings, current, and fixed deposit. Each account has deposit and withdrawal rules, with specific interest calculations and overdraft facilities.

---

### Unit III: Polymorphism

1. **Program 01: CAD Shape Drawing System** Description: A CAD system needs to handle different geometric shapes like circles, rectangles, and triangles. Each shape is drawn on screen and its area is calculated using a common interface.

2. **Program 02: Complex Number Calculator** Description: A scientific application needs to perform mathematical operations on complex numbers. Operators like addition, subtraction, multiplication, and equality comparison are overloaded to work with complex numbers directly.

3. **Program 03: Input Validation Service** Description: A system validates different types of user inputs such as marks, monetary amounts, and user names. The validation logic is implemented using overloaded functions for each data type.

4. **Mini Project: Polymorphic Media Player System** Description: A media player handles playback for different media types like audio tracks, video clips, and images. All media items are controlled using standard operations like play, pause, and stop through base class pointers.

---

## Codebook Programs Summary

### Unit 1 Codebook
- `code_1.cpp` - Basic data types (int, char, float) and printing student details.
- `code_2.cpp` - If-else statement to check whether a student passes or fails.
- `code_3.cpp` - Storing student marks in an array and printing them using a for loop.
- `code_4.cpp` - User defined function with prototype to calculate sum of two numbers.
- `code_5.cpp` - Simple Student class with name and age variables and display function.
- `code_6.cpp` - Constructor and destructor execution during object creation and termination.
- `code_7.cpp` - Static count variable to track the total number of objects created.
- `code_8.cpp` - Private variables, inline getter method, and friend function.

### Unit 2 Codebook
- `code_1.cpp` - Single inheritance where Student inherits from Person class.
- `code_2.cpp` - Developer class inherits from Employee and adds programming language.
- `code_3.cpp` - Difference between public and private inheritance access modes.
- `code_4.cpp` - Multilevel inheritance hierarchy (Person -> Employee -> Manager).
- `code_5.cpp` - Hierarchical inheritance with Car and Bike inheriting from Vehicle.
- `code_6.cpp` - Multiple inheritance with StudentAthlete inheriting from Academic and Sports.
- `code_7.cpp` - Resolving function name conflict in multiple inheritance using scope resolution (`::`).
- `code_8.cpp` - Order of constructor and destructor execution in inheritance.
- `code_9.cpp` - Passing arguments to base class constructor using member initializer list.
- `code_10.cpp` - Basic virtual function and runtime polymorphism using base pointer.
- `code_11.cpp` - Pure virtual function and abstract class (Appliance and Fan).
- `code_12.cpp` - Resolving diamond problem using virtual base class (`virtual public`).
- `code_13.cpp` - Friend class allowing KeyInspector to read private data of SecretData.
- `code_14.cpp` - Nested class with Core class defined inside CPU class.
- `code_15.cpp` - Overriding rental cost calculation in LuxuryCar derived from Vehicle.
- `code_16.cpp` - Abstract Employee class with pure virtual salary calculation function.

### Unit 3 Codebook
- `code_1.cpp` - Function overloading for adding integers, floating-point numbers, and strings.
- `code_2.cpp` - Function overloading to calculate area of square, rectangle, circle, and triangle.
- `code_3.cpp` - Overloading unary minus (`-`) operator for Number and Balance classes.
- `code_4.cpp` - Overloading prefix and postfix `++` and `--` operators in Counter class.
- `code_5.cpp` - Overloading binary `+` and `-` operators for complex number arithmetic.
- `code_6.cpp` - Overloading relational operators `>` and `==` to compare Distance objects.
- `code_7.cpp` - Operator overloading with friend functions to support syntax like `10 + Complex`.
- `code_8.cpp` - Static early binding demonstration without virtual keyword.
- `code_9.cpp` - Dynamic late binding using virtual function `sound()` across animal classes.
- `code_10.cpp` - Passing base reference to function to avoid object slicing.
- `code_11.cpp` - Pure virtual area function in Shape implemented by Rectangle and Triangle.
- `code_12.cpp` - Storing derived shape objects in vector using smart pointers (`unique_ptr`).
- `code_13.cpp` - Virtual destructor to ensure proper cleanup of derived objects.
- `code_14.cpp` - Demonstrating object slicing: pass by value vs pass by reference/pointer.
- `code_15.cpp` - Payment gateway system supporting Card, UPI, NetBanking, and Wallet payments.
- `code_16.cpp` - Polymorphic payroll system with Permanent, Contract, and Freelance employees.


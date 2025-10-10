# 🚀 CPP Modules

**C++ Programming Fundamentals** - Ecole42 projesi kapsamında geliştirilmiş, modern C++ programlama teknikleri ve nesne yönelimli programlama kavramlarını öğreten kapsamlı bir C++ projesi.

## 📖 Proje Hakkında

CPP Modules, C++ programlama dilinin temel kavramlarından ileri seviye özelliklerine kadar geniş bir yelpazede eğitim veren modüler bir projedir. Her modül, belirli C++ konularına odaklanır ve pratik uygulamalarla öğrenmeyi destekler.

### 🎯 Proje Amacı

- **Object-Oriented Programming**: Nesne yönelimli programlama
- **Memory Management**: Bellek yönetimi
- **Templates**: Template programlama
- **STL**: Standard Template Library
- **Advanced C++**: İleri seviye C++ özellikleri

## 🏗️ Proje Yapısı

```
cpp-modules/
├── cpp00/                  # Module 00: C++ Basics
│   ├── ex00/              # Megaphone - String manipulation
│   └── ex01/              # PhoneBook - Class basics
├── cpp01/                  # Module 01: Memory Management
│   ├── ex00/              # Zombie - Dynamic allocation
│   ├── ex01/              # Zombie Horde - Array allocation
│   └── ex02/              # References - Reference variables
├── cpp02/                  # Module 02: Classes & Objects
│   ├── ex00/              # Fixed Point - Fixed point arithmetic
│   ├── ex01/              # Fixed Point - Operator overloading
│   ├── ex02/              # Fixed Point - Comparison operators
│   └── ex03/              # BSP - Point in triangle algorithm
├── cpp03/                  # Module 03: Inheritance
│   ├── ex00/              # ClapTrap - Basic inheritance
│   ├── ex01/              # ScavTrap - Virtual functions
│   └── ex02/              # FragTrap - Multiple inheritance
├── cpp04/                  # Module 04: Polymorphism
│   ├── ex00/              # Animal - Virtual functions
│   ├── ex01/              # Brain - Deep copy
│   └── ex02/              # Abstract classes
├── cpp05/                  # Module 05: Exceptions
│   ├── ex00/              # Bureaucrat - Exception handling
│   ├── ex01/              # Form - Custom exceptions
│   ├── ex02/              # Form - Form system
│   └── ex03/              # Intern - Factory pattern
├── cpp06/                  # Module 06: Type Casting
│   ├── ex00/              # ScalarConverter - Type conversion
│   ├── ex01/              # Serializer - Data serialization
│   └── ex02/              # Base - Dynamic casting
├── cpp07/                  # Module 07: Templates
│   ├── ex00/              # Function templates
│   ├── ex01/              # Iterator templates
│   └── ex02/              # Array template class
└── cpp08/                  # Module 08: STL
    ├── ex00/              # EasyFind - STL algorithms
    └── ex01/              # Span - Container implementation
```

## 🚀 Kullanım

### Derleme
```bash
# Tüm modülleri derle
make

# Belirli bir modülü derle
cd cpp00/ex00
make
```

### Çalıştırma
```bash
# Örnek çalıştırma
./megaphone "Hello World"
./phonebook
./claptrap
```

## 📚 Modül Detayları

### Module 00: C++ Basics
- **Megaphone**: String manipulation ve I/O
- **PhoneBook**: Class yapısı ve encapsulation

### Module 01: Memory Management
- **Zombie**: Dynamic memory allocation
- **Zombie Horde**: Array allocation ve management
- **References**: Reference variables ve pointers

### Module 02: Classes & Objects
- **Fixed Point**: Fixed point arithmetic
- **Operator Overloading**: Custom operators
- **BSP**: Point-in-triangle algorithm

### Module 03: Inheritance
- **ClapTrap**: Basic inheritance
- **ScavTrap**: Virtual functions
- **FragTrap**: Multiple inheritance

### Module 04: Polymorphism
- **Animal**: Virtual functions ve polymorphism
- **Brain**: Deep copy ve memory management
- **Abstract Classes**: Pure virtual functions

### Module 05: Exceptions
- **Bureaucrat**: Exception handling
- **Form**: Custom exception classes
- **Intern**: Factory pattern

### Module 06: Type Casting
- **ScalarConverter**: Type conversion
- **Serializer**: Data serialization
- **Base**: Dynamic casting

### Module 07: Templates
- **Function Templates**: Generic programming
- **Iterator Templates**: STL-style iterators
- **Array Template**: Custom container

### Module 08: STL
- **EasyFind**: STL algorithms
- **Span**: Container implementation

## 🔧 Teknik Özellikler

### Object-Oriented Programming
- **Classes**: Class definition ve implementation
- **Inheritance**: Single ve multiple inheritance
- **Polymorphism**: Virtual functions
- **Encapsulation**: Data hiding

### Memory Management
- **Dynamic Allocation**: new/delete operators
- **RAII**: Resource Acquisition Is Initialization
- **Smart Pointers**: Modern memory management
- **Memory Leaks**: Prevention techniques

### Templates
- **Function Templates**: Generic functions
- **Class Templates**: Generic classes
- **Template Specialization**: Special cases
- **STL Integration**: Standard library usage

### Exception Handling
- **Try-Catch**: Exception handling
- **Custom Exceptions**: User-defined exceptions
- **Exception Safety**: Exception-safe code
- **RAII**: Resource management

## 🎨 Özellikler

- ✅ **Object-Oriented Design**: Nesne yönelimli tasarım
- ✅ **Memory Management**: Bellek yönetimi
- ✅ **Template Programming**: Template programlama
- ✅ **STL Usage**: Standard library kullanımı
- ✅ **Exception Handling**: Hata yönetimi
- ✅ **Design Patterns**: Tasarım desenleri
- ✅ **Modern C++**: Modern C++ özellikleri

## 🔍 Test Senaryoları

### Module 00 Tests
```bash
# Megaphone test
./megaphone "Hello World"
./megaphone "shhhhh... I think the students are asleep..."

# PhoneBook test
./phonebook
# Interactive phone book management
```

### Module 01 Tests
```bash
# Zombie test
./newZombie "Zombie1"
./randomChump "Zombie2"

# Zombie Horde test
./zombieHorde 5 "Zombie"
```

### Module 02 Tests
```bash
# Fixed Point test
./fixed_point
# Fixed point arithmetic operations

# BSP test
./bsp
# Point in triangle algorithm
```

## 📊 Performans

- **Memory Efficiency**: Optimized memory usage
- **Template Performance**: Zero-cost abstractions
- **Exception Safety**: Exception-safe operations
- **STL Integration**: Efficient standard library usage

## 🛠️ Geliştirme Ortamı

- **Dil**: C++98/03/11/14/17
- **Derleyici**: g++/clang++
- **Platform**: Linux/macOS
- **Standart**: C++98 ve üzeri
- **Kütüphaneler**: STL, iostream

## 📚 Öğrenilen Kavramlar

### C++ Fundamentals
- **Syntax**: C++ syntax ve semantics
- **Data Types**: Built-in ve user-defined types
- **Functions**: Function overloading ve templates
- **Classes**: Class definition ve usage

### Object-Oriented Programming
- **Inheritance**: Class inheritance
- **Polymorphism**: Virtual functions
- **Encapsulation**: Data hiding
- **Abstraction**: Abstract classes

### Advanced C++
- **Templates**: Generic programming
- **STL**: Standard Template Library
- **Exception Handling**: Error management
- **Design Patterns**: Common patterns

### Memory Management
- **Dynamic Allocation**: new/delete
- **RAII**: Resource management
- **Smart Pointers**: Modern memory management
- **Memory Leaks**: Prevention

## 🔧 Geliştirme Notları

- **RAII Principle**: Resource management
- **Exception Safety**: Exception-safe code
- **Template Design**: Generic programming
- **STL Integration**: Standard library usage
- **Performance Optimization**: Code optimization

## 📝 Lisans

Bu proje Ecole42 eğitim programı kapsamında geliştirilmiştir.

## 👨‍💻 Geliştirici

**Haluk Özdemir**  
42 Istanbul - C++ Programming

---

*Bu proje, modern C++ programlama ve nesne yönelimli programlama temellerini öğrenmek için tasarlanmıştır. C++ dilinin temel kavramlarından ileri seviye özelliklerine kadar geniş bir yelpazede eğitim verir ve gerçek dünya C++ programlama deneyimi kazandırır.*

---

# 🚀 CPP Modules

**C++ Programming Fundamentals** - A comprehensive C++ project developed within the scope of Ecole42, teaching modern C++ programming techniques and object-oriented programming concepts.

## 📖 About the Project

CPP Modules is a modular project that provides education on C++ programming from basic concepts to advanced features. Each module focuses on specific C++ topics and supports learning through practical applications.

### 🎯 Project Purpose

- **Object-Oriented Programming**: Object-oriented programming
- **Memory Management**: Memory management
- **Templates**: Template programming
- **STL**: Standard Template Library
- **Advanced C++**: Advanced C++ features

## 🏗️ Project Structure

```
cpp-modules/
├── cpp00/                  # Module 00: C++ Basics
│   ├── ex00/              # Megaphone - String manipulation
│   └── ex01/              # PhoneBook - Class basics
├── cpp01/                  # Module 01: Memory Management
│   ├── ex00/              # Zombie - Dynamic allocation
│   ├── ex01/              # Zombie Horde - Array allocation
│   └── ex02/              # References - Reference variables
├── cpp02/                  # Module 02: Classes & Objects
│   ├── ex00/              # Fixed Point - Fixed point arithmetic
│   ├── ex01/              # Fixed Point - Operator overloading
│   ├── ex02/              # Fixed Point - Comparison operators
│   └── ex03/              # BSP - Point in triangle algorithm
├── cpp03/                  # Module 03: Inheritance
│   ├── ex00/              # ClapTrap - Basic inheritance
│   ├── ex01/              # ScavTrap - Virtual functions
│   └── ex02/              # FragTrap - Multiple inheritance
├── cpp04/                  # Module 04: Polymorphism
│   ├── ex00/              # Animal - Virtual functions
│   ├── ex01/              # Brain - Deep copy
│   └── ex02/              # Abstract classes
├── cpp05/                  # Module 05: Exceptions
│   ├── ex00/              # Bureaucrat - Exception handling
│   ├── ex01/              # Form - Custom exceptions
│   ├── ex02/              # Form - Form system
│   └── ex03/              # Intern - Factory pattern
├── cpp06/                  # Module 06: Type Casting
│   ├── ex00/              # ScalarConverter - Type conversion
│   ├── ex01/              # Serializer - Data serialization
│   └── ex02/              # Base - Dynamic casting
├── cpp07/                  # Module 07: Templates
│   ├── ex00/              # Function templates
│   ├── ex01/              # Iterator templates
│   └── ex02/              # Array template class
└── cpp08/                  # Module 08: STL
    ├── ex00/              # EasyFind - STL algorithms
    └── ex01/              # Span - Container implementation
```

## 🚀 Usage

### Compilation
```bash
# Compile all modules
make

# Compile specific module
cd cpp00/ex00
make
```

### Execution
```bash
# Example execution
./megaphone "Hello World"
./phonebook
./claptrap
```

## 📚 Module Details

### Module 00: C++ Basics
- **Megaphone**: String manipulation and I/O
- **PhoneBook**: Class structure and encapsulation

### Module 01: Memory Management
- **Zombie**: Dynamic memory allocation
- **Zombie Horde**: Array allocation and management
- **References**: Reference variables and pointers

### Module 02: Classes & Objects
- **Fixed Point**: Fixed point arithmetic
- **Operator Overloading**: Custom operators
- **BSP**: Point-in-triangle algorithm

### Module 03: Inheritance
- **ClapTrap**: Basic inheritance
- **ScavTrap**: Virtual functions
- **FragTrap**: Multiple inheritance

### Module 04: Polymorphism
- **Animal**: Virtual functions and polymorphism
- **Brain**: Deep copy and memory management
- **Abstract Classes**: Pure virtual functions

### Module 05: Exceptions
- **Bureaucrat**: Exception handling
- **Form**: Custom exception classes
- **Intern**: Factory pattern

### Module 06: Type Casting
- **ScalarConverter**: Type conversion
- **Serializer**: Data serialization
- **Base**: Dynamic casting

### Module 07: Templates
- **Function Templates**: Generic programming
- **Iterator Templates**: STL-style iterators
- **Array Template**: Custom container

### Module 08: STL
- **EasyFind**: STL algorithms
- **Span**: Container implementation

## 🔧 Technical Features

### Object-Oriented Programming
- **Classes**: Class definition and implementation
- **Inheritance**: Single and multiple inheritance
- **Polymorphism**: Virtual functions
- **Encapsulation**: Data hiding

### Memory Management
- **Dynamic Allocation**: new/delete operators
- **RAII**: Resource Acquisition Is Initialization
- **Smart Pointers**: Modern memory management
- **Memory Leaks**: Prevention techniques

### Templates
- **Function Templates**: Generic functions
- **Class Templates**: Generic classes
- **Template Specialization**: Special cases
- **STL Integration**: Standard library usage

### Exception Handling
- **Try-Catch**: Exception handling
- **Custom Exceptions**: User-defined exceptions
- **Exception Safety**: Exception-safe code
- **RAII**: Resource management

## 🎨 Features

- ✅ **Object-Oriented Design**: Object-oriented design
- ✅ **Memory Management**: Memory management
- ✅ **Template Programming**: Template programming
- ✅ **STL Usage**: Standard library usage
- ✅ **Exception Handling**: Error management
- ✅ **Design Patterns**: Design patterns
- ✅ **Modern C++**: Modern C++ features

## 🔍 Test Scenarios

### Module 00 Tests
```bash
# Megaphone test
./megaphone "Hello World"
./megaphone "shhhhh... I think the students are asleep..."

# PhoneBook test
./phonebook
# Interactive phone book management
```

### Module 01 Tests
```bash
# Zombie test
./newZombie "Zombie1"
./randomChump "Zombie2"

# Zombie Horde test
./zombieHorde 5 "Zombie"
```

### Module 02 Tests
```bash
# Fixed Point test
./fixed_point
# Fixed point arithmetic operations

# BSP test
./bsp
# Point in triangle algorithm
```

## 📊 Performance

- **Memory Efficiency**: Optimized memory usage
- **Template Performance**: Zero-cost abstractions
- **Exception Safety**: Exception-safe operations
- **STL Integration**: Efficient standard library usage

## 🛠️ Development Environment

- **Language**: C++98/03/11/14/17
- **Compiler**: g++/clang++
- **Platform**: Linux/macOS
- **Standard**: C++98 and above
- **Libraries**: STL, iostream

## 📚 Learned Concepts

### C++ Fundamentals
- **Syntax**: C++ syntax and semantics
- **Data Types**: Built-in and user-defined types
- **Functions**: Function overloading and templates
- **Classes**: Class definition and usage

### Object-Oriented Programming
- **Inheritance**: Class inheritance
- **Polymorphism**: Virtual functions
- **Encapsulation**: Data hiding
- **Abstraction**: Abstract classes

### Advanced C++
- **Templates**: Generic programming
- **STL**: Standard Template Library
- **Exception Handling**: Error management
- **Design Patterns**: Common patterns

### Memory Management
- **Dynamic Allocation**: new/delete
- **RAII**: Resource management
- **Smart Pointers**: Modern memory management
- **Memory Leaks**: Prevention

## 🔧 Development Notes

- **RAII Principle**: Resource management
- **Exception Safety**: Exception-safe code
- **Template Design**: Generic programming
- **STL Integration**: Standard library usage
- **Performance Optimization**: Code optimization

## 📝 License

This project was developed within the scope of the Ecole42 education program.

## 👨‍💻 Developer

**Haluk Özdemir**  
42 Istanbul - C++ Programming

---

*This project is designed to learn modern C++ programming and object-oriented programming fundamentals. It provides education on C++ programming from basic concepts to advanced features and provides real-world C++ programming experience.*

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.s1 = "Hello";
    data.i = 42;
    data.s2 = "World";
    data.b = true;
    data.c = 'A';
    data.f = 3.14f;
    data.d = 2.71828;
    data.s = 123;
    data.l = 1234567890;

    Data* originalPtr = &data;

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Data content: s1='" << data.s1 << "', i=" << data.i << ", s2='" << data.s2 
              << "', b=" << data.b << ", c='" << data.c << "', f=" << data.f 
              << ", d=" << data.d << ", s=" << data.s << ", l=" << data.l << std::endl;

    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
    {
        std::cout << "SUCCESS: Pointers are equal!" << std::endl;
        std::cout << "Data content after deserialization: s1='" << deserializedPtr->s1 
                  << "', i=" << deserializedPtr->i << ", s2='" << deserializedPtr->s2 
                  << "', b=" << deserializedPtr->b << ", c='" << deserializedPtr->c 
                  << "', f=" << deserializedPtr->f << ", d=" << deserializedPtr->d 
                  << ", s=" << deserializedPtr->s << ", l=" << deserializedPtr->l << std::endl;
    }
    else
        std::cout << "ERROR: Pointers are not equal!" << std::endl;

    return 0;
}

#include "basic_type.h"
#include "compound_type.h"
#include <iostream>

template <typename T>
void TestBuildIn(const T &val) {
    if (IsBuildInType<T>::kYes) {
        std::cout << "build-in type" << std::endl;
    } else {
        if (CompoundType<T>::kIsPointer) {
            std::cout << "pointer type" << std::endl;
        } 
        if (CompoundType<T>::kIsReference) {
            std::cout << "reference type" << std::endl;
        }
        if (CompoundType<T>::kIsArray) {
            std::cout << "array type" << std::endl;
        } 
        if (CompoundType<T>::kIsFunction) {
            std::cout << "function type" << std::endl;
        }
    }
}

class Test {

};

void test_fun() {

}

int main() {
    TestBuildIn(10);
    TestBuildIn("helloworld"); //should be array type
    TestBuildIn('a');
    TestBuildIn(-3.14159);
    TestBuildIn(true);

    TestBuildIn(std::cin);
    TestBuildIn(std::cout);
    TestBuildIn(Test());

    int a = 10;
    TestBuildIn(&a);
    int &b = a;
    TestBuildIn<int&>(b);

    int c[1] = {0};
    TestBuildIn(c); 
    int d[0];
    TestBuildIn(d);

    TestBuildIn(test_fun);


    return 0;
}
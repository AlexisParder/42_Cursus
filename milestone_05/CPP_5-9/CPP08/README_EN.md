[🇫🇷 French](./README.md)
# Essential Concepts for This Module

`std::vector` is a dynamic array that automatically grows as needed:
```cpp
std::vector<int> v;
v.push_back(42);  // adds an element
v.push_back(10);
```

`Iterators` — they are like pointers to elements within a container:
```cpp
std::vector<int>::iterator it = v.begin(); // points to the first element
std::vector<int>::iterator ite = v.end();  // points PAST the last element

while (it != ite)
{
    std::cout << *it << std::endl; // dereference like a pointer
    it++;
}
```

`Algorithms` are generic functions that operate using iterators:
```cpp
#include <algorithm>

std::find(v.begin(), v.end(), 42); // searches for 42 in v
std::sort(v.begin(), v.end());     // sorts v
```

> These three concepts are closely related: `algorithms` take `iterators`, which point to elements inside `containers`.

# Resources
- [Containers in C++ STL](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/)
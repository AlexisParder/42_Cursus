[🇬🇧 English](./README_EN.md)
# Concepts essentiels pour ce module

`std::vector` est un tableau dynamique qui grandit automatiquement :

```cpp
std::vector<int> v;
v.push_back(42);  // ajoute un élément
v.push_back(10);
```

`Les itérateurs` — ce sont comme des pointeurs sur un élément du conteneur :
```cpp
std::vector<int>::iterator it = v.begin(); // pointe sur le 1er élément
std::vector<int>::iterator ite = v.end();  // pointe APRÈS le dernier
while (it != ite)
{
    std::cout << *it << std::endl; // déréférence comme un pointeur
    it++;
}
```

`Les algorithmes` ce sont des fonctions génériques qui utilisent des itérateurs :
```cpp
#include <algorithm>
std::find(v.begin(), v.end(), 42); // cherche 42 dans v
std::sort(v.begin(), v.end());     // trie v
```

> Ces trois concepts sont liés : les `algorithmes` prennent des `itérateurs` qui pointent sur des `conteneurs`.
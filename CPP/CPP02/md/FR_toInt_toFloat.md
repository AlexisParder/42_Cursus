Le principe du virgule fixe avec 8 bits fractionnaires :
Quand tu stockes 1 en virgule fixe, tu stockes en réalité 1 × 256 = 256 dans _value. Les 8 derniers bits représentent la partie décimale.
```
_value = 256  →  représente  1.0
_value = 512  →  représente  2.0
_value = 128  →  représente  0.5
```

Constructeur int → virgule fixe :
```
cpp_value = n << 8;
// n = 1  →  _value = 1 × 256 = 256
// n = 2  →  _value = 2 × 256 = 512
```
Décaler de 8 bits à gauche = multiplier par 256.

Constructeur float → virgule fixe :
```
cpp_value = roundf(f * 256);
// f = 1.5  →  _value = 1.5 × 256 = 384
// f = 42.42 →  _value = 42.42 × 256 = 10859
```

toFloat → virgule fixe vers float :
```
cppreturn (float)_value / 256;
// _value = 384  →  384 / 256 = 1.5
```
toInt → virgule fixe vers int :
```
cppreturn _value >> 8;
// _value = 384  →  384 / 256 = 1
```
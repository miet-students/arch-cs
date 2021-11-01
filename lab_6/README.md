## Задание 1

Вычислите для заданного целого знакового `x`:

```
f(x) = (x < 7)
```

Вывод:

```
x: -10
C++ x < 7: True
ASM x < 7: True

x: 0
C++ x < 7: True
ASM x < 7: True

x: 3
C++ x < 7: True
ASM x < 7: True

x: 7
C++ x < 7: False
ASM x < 7: False

x: 10
C++ x < 7: False
ASM x < 7: False
```

## Задание 2

Вычислите для заданного целого знакового `x`:

```
y(x) | x < 3     = 4
     | otherwise = 8*x - 52
```

Вывод:

```
x: -10
C++ y(x): 4
ASM y(x): 4

x: 0
C++ y(x): 4
ASM y(x): 4

x: 3
C++ y(x): -28
ASM y(x): -28

x: 6
C++ y(x): -4
ASM y(x): -4

x: 10
C++ y(x): 28
ASM y(x): 28
```

## Задание 3

Вычислите для заданного вещественного `x`:

```
y(x) | x < 3.3     = 4.6
     | otherwise   = x + 6.9
```

Вывод:

```
x: 0
C++ y(x): 4.6
ASM y(x): 4.6

x: 3
C++ y(x): 4.6
ASM y(x): 4.6

x: 7.1
C++ y(x): 14
ASM y(x): 14

x: 10.7514
C++ y(x): 17.6514
ASM y(x): 17.6514
```

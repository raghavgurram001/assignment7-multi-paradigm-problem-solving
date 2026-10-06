# Assignment 7 – Statistics Calculator

A multi-language implementation of basic descriptive statistics: **mean**, **median**, and **mode**.  
The same logic is implemented in C, OCaml, and Python for comparison across programming paradigms.

## Project Structure

```text
assignment7/
├── c/
│   └── statistics.c
├── ocaml/
│   └── statistics.ml
└── python/
    └── statistics.py
```

## Implementations

- **C** – Procedural implementation using `qsort`, loops, and manual memory management.
- **OCaml** – Functional implementation using recursion, `List.fold_left`, and immutable data.
- **Python** – Object-oriented implementation using a class and `collections.Counter`.

All versions use the same tie-breaking rule for the mode: if multiple values have the highest frequency, the smallest value is returned.

## How to Run

### C

```bash
cd assignment7/c
gcc -o statistics statistics.c
./statistics
```

### OCaml

```bash
cd assignment7/ocaml
ocamlc -o statistics statistics.ml
./statistics
```

### Python

```bash
cd assignment7/python
python3 statistics.py
```

## Requirements

- GCC compiler
- OCaml compiler (`ocamlc`)
- Python 3

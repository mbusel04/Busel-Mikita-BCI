# Busel-Mikita
## Code Sample - Matrix Multiplication and Transposition
The main body of the code is the `MatrixService` class. That service is realized as a singleton, with multiple methods focused on operations on matrices. 
Matrices are represented in the form of a `MatrixStruct` container, which contains the size properties of the matrix, as well as its entries in the form of a 2D array.
Also `MatrixService` includes the additional method `getMatrixMaT(mat)` which returns the product of the input matrix and the input's matrix transpose.

After the compilation of most essential methods of `MatrixService` are run through a series of unit tests with the use of `testMatrixService.cpp`, which failure cases will announced to the user right after the compilation process is finished. 

In addition to the main functionality code, the repository includes the `demoMatrixService.cpp` file in order to give a user a chance to try out the capabilities of a library in practice. 

## Compilation And Run

Here are brief instructions on how to compile the library and demo, as well as to run it. 

\**Note: Code will ask the user to type in entries of the matrix, inputted elements by the user will fill up the matrix from left to right and top to bottom. *
* The program would not stop until it receives the minimum quantity of elements to fill up the matrix. Any extra elements input by the user will be ignored. *
* User can input elements as long as they are separated by space or newline.*
* Input examples: *
```bash
Type in the 6 entries of matrix:
1 2 3 4 5 6
# Valid input.
# ~~~
Type in the 6 entries of matrix:
1 
2 3
4 5 6
# Also valid input, which will lead to the same matrix input.
```


Execute `run.sh` in order to launch the demo:
```bash
bash run.sh
```
It will automatically compile the library, tests, and demo file. As well as will also start the demo after a small delay. 

In cases if the user wants only to compile the program without its immediate call:
```bash
make
```
In order to run the compiled program:
```bash
./demo.out
```

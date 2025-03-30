# Operating Systems Projects

This directory contains a collection of tasks and projects completed as part of the "Operating Systems" course. These projects include shell scripts and Ada programs, demonstrating various aspects of system programming.

## Contents

1. **file-split.cpp**: A C++ program for splitting files into smaller parts.
2. **occurrences.sh**: A shell script that counts occurrences of a given pattern in a file.
3. **file-rights.sh**: A shell script that displays file access rights in a specified directory.
4. **fibonacci.sh**: A shell script that generates the Fibonacci sequence up to a specified number.
5. **mean-and-variance.sh**: A shell script that calculates the mean and variance of a set of numbers from a file.
6. **identifier.sh**: A shell script that checks whether a given string is a valid identifier in a programming language.
7. **synchronizer.adb**: An Ada program implementing synchronization mechanisms between processes or threads.

## Requirements

- A POSIX-compliant operating system.
- Bash interpreter (for shell scripts).
- GNAT compiler (for Ada programs).
- C++ compiler (for C++ programs).

## Usage

### Shell Scripts

To execute any of the shell scripts, use the following command:
```sh
bash script-name.sh
```
For example:
```sh
bash fibonacci.sh 10
```
This will generate the first 10 numbers in the Fibonacci sequence.

### C++ Program

Compile the C++ program with:
```sh
g++ file-split.cpp -o file-split
```
Then run it:
```sh
./file-split input.txt 1024
```
This will split `input.txt` into 1024-byte chunks.

### Ada Program

Compile the Ada program with:
```sh
gnatmake synchronizer.adb
```
Then execute it:
```sh
./synchronizer
```

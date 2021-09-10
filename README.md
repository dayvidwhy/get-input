# Get Input
Utility function for dynamically allocating increasing amounts of memory as contents of a file is read.

## Installation
```bash
git clone git@github.com:dayvidwhy/get-input.git
cd get-input
make
./read file
# check usage for any errors
```

## How it works
We `malloc` a set amount of memory then continuously `realloc` additional memory as the number of bytes becomes insufficient to store our read input.

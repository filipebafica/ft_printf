# ft_printf
An implementation of libc's printf function.

## 🗂 Table of Contents
* [About](#-about)
* [Getting Started](#-getting-started)
* [How to Use](#-how-to-use)
* [42 École | 42 São Paulo](#-42-école--42-são-paulo)

## 🧐 About
This is an implementation of a function that handles and prints different data types.

The function will do the following conversions:
* %c print a single character.
* %s print a string of characters.
* %p The void * pointer argument is printed in hexadecimal.
* %d print a decimal (base 10) number.
* %i print an integer in base 10.
* %u print an unsigned decimal (base 10) number.
* %x print a number in hexadecimal (base 16).
* %% print a percent sign.

The function returns:
* The number of characters printed (excluding the null byte).

Prototype: 
* `int	ft_printf(const char *format, ...)`

This project is part of 42 École/ 42 SP curriculum.\
Topics such as variadic functions and data types manipulation were addressed.

## 🏁 Getting Started
The `gcc` compiler is needed.

#### ⚙️ Installing
To compile the code, clone the repo, and run the command `make`.
```
$ git clone https://github.com/filipebafica/ft_printf.git
$ cd ft_printf
$ make
```
This is going to generate a `ft_printf.a` file that you can compile with your source code.
```
$ gcc my_source.c -I ./ft_printf/includes ./ft_printf/ft_printf.a
$ ./a.out
```
## 🎈 How to Use
Call the function passing a string and specifiers as seen below:
```
#include "ft_printf.h"

int	main(void)
{
	char	*var;

	var = "Hello World";
	ft_printf("Print this: %s\n", var);
	return (0);
}
```
## 🏫 42 École | 42 São Paulo
42 École is a network of tech schools spread around the world where anyone can learn how to code for free.\
At 42 there are no teachers or classrooms, each student learns from and works with each other (peer-to-peer learning).\
To see more go to https://www.42.fr/ and https://www.42sp.org.br/.

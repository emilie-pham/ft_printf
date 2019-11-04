# ft_printf
  
Summary:  
By now, you must be fed up alternating the ft_putstr and ft_putnbr
functions when doing your printing. Are you not allowed to use printf? You can recode
yours! It will be a chance for you to discover a feature of the C language – variadic
functions – and to practice detailed management of the printing options. You will then
be allowed to use your ft_printf in all your future projects.

Objectives:  
This project will enable you to discover variadic functions
in C in a particularly relevant context as well as learn about a great example of a basic
“dispatcher” in C via the use of an array of function’s pointers.
  
  
Prototype  
```
int ft_printf( const char *restrict format, ... );
```
  
### Usage
```make``` then compile the program in which you want to use ft_printf with the ```libftprintf.a```  
  
Conversions handled by ft_printf:  
```
• %c %s %p  
• %d %i %o %u %x %X with the following flags: hh, h, l and ll  
• %f with the following flags: l and L  
• %%  
• flags #0-+ and space
• minimum field-width
• precision
```
  
Obtained mark for this project : 96/100

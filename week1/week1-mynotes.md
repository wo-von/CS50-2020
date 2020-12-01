* there are so man abstraction and so many humans before us that we do not nned to write binary, which is the only language that the machine understands
* we have inputs and we have some outputs and we need to solve a problem to get to the desired outputs but we need to represent this input and output
* Since computers oly understadn zeros and ones, we use abstractions and standards for representing real world data:
    - ASCII for letters
    - RGB for clors
* ad from colors we can have images, so the abstraction goes higer and higher
* here we just assume that inputs and outputs are well abstracted an drepresented and if they get very distant memory for us, we can be sure that some one is doing them (abstraction again!)
* our solution should be precise enough, we have previously done this using scratch or pseudo-code, but it is still not precise enough
* for example in the phone book pseudocode, call mike is an aabstraction which is usefull, butmight not be precise enough and entails a lot of assumptions
* we cannot afford too many assumptions and ot thinking about corner cases with programming languages,
  * humans do man abstractions, but this not true for computers, they need clear instructions 
* we or some one need to do the level of precision that is needed, later on, it can be reused.
* then they can be used as puzzle pieces.
* C is text based, but at first looks cryptic.
* At first we might have a lot of syntatic problems (semicolon, paranthesis), but these are of least of importance. we should see past that
* With training, these stuff goes away and we see the important fundamentals.
* *printf:* f stands for formatted ad what should be said in "". Also new line should be specified: \n (different levels of precisions), also most lines should end in ;
    - *printf("Hello, World!\n");*
* *Variable:* Counter = 0 
    - also type should be specified and the line should be finished with ;
    - int counter = 0;
* changing a variable:
    - counter = counter + 1;
    - here = does not mean "equals" but means "assignment"
    - but int is not necessary, we have  done this before
    - or: counter += 1; (syntatic sugar: fewer words but doing the same thing)
    - or counter++;
* condition: if (x < y){} (if the {} is a one liner, it is not necessary)
*  if .... else:
```C
if (x < y){
    printf(" Hello, World!\n");
} else {
    printf("x is not less than y\n");
}
```
* There are many different types of style, but generally spaces are for humans mostly and does not matter to computers.
* We have also the idea of if(){}else if(){}else if(){}
* logical operands: < > == (= meansa assignment so we use == for equality ad comparing) <= >=
* Another way, but with a defualt case: if(){}else if (){} else(){} (no evaluation for the thirs condition)
* *while()*
```C
while () // we need a question here in a paanthesis, for forever we can use a // mathematically correct thing, OR TRUE (C syntax) 
{

}
```
* Loops: we nned a variable to keeo trackl of how many times we hae done sths
```C
    for (int i = 0; i < 50; i++)
    // give me avariable, i, let me store integers in it,and 
    // set the initial varibale to zero, we use 0 because it is the smallest // and should not be wasted.
    // i++ is equal to i = i+1
    {
        printf("Hello, World~\n");
    } 
    // so fisrty we assign 0, check if it is smaller than the second condition, if yes do the {} part and then put i=i+1 and check the condition again, and so on, untill 50<50 is untrue (we did 50 times, because we included 0 too)
```
* get_string("what is your name?\n");
    - a string is a sequnce of characters, word, sentence, paagraph
    - we also need a place where we put the retuen value of this function so:
    - string answer = get_string("what is your name?\n");
    - so whatever the function get_string comes back with is stored in string answer.
    - printf("%s", answer);
        + before comma: print something that looks like this, and %s is a place holder for a string
        + later this string is replaces and plugged in by "string answer"
        + this is a bit not very intuitive, but this is how it works.
        + It also can be seen that printf is getting two arguments: the string between "s with placeholder and \n etc, and the variables to replace the placeholders
    - printf(" Hello, %s!\n", answer);
    - so this is not a formatted string
* Sandbox: CS50's webbasec IDE
    * It is cloud based
    - we have a text editor
    - and a terminal window
    - C rpograms are written by human convention in whateevr.c
    - this is called source code
    - we should run this, but it is not binary (zeros and ones)
    - converting this source code to binary is called compile
    - source code generally means a code that humans have written (C, java, etc.)
    - CPUs are hardwired at the factories to understand zeros and ones.
    - the step of compilation ad been dones before
    - $ is a prompt and means waiting for us to type sth.
    - GUI was not there before ad everything had to be typed, it is less beautiful but more powerfull. and gives us access to the underlying server
    - we use clang (stands for C languages) for compilation. the output for historical reasons is called a.out (assembly output)
    - run : ./a.out (equivalant of double clicking)
    - Arguments: inputs typed in via command line, so they are a way to change the default behaviour of a command in the command line
        + clang -o hello hello.c
    - Easier way: make hello 
        + hello is the name of the program to be made
        + looks by default for hello.c
        + there are a ot of configurations, that make additional features possible
        + make automates all these configurations
        + make is not a compilaer which uses clang in an automated way
    - for ebugging start at the top, it is usually somehting there which gets cascaded.
    - C has integers and char and .. but no string!
    - we #include <cs50.h> (also get_string is there)
    - so we have more puzzle pieces.
    - stdio comes with c and includes for example printf
    - string and get_string and so are included in a file called cs50.h
    - %s for string and a second argument after comma for plugging in
    - every time the code is changed, it should be recompiled
* Functions then can take inputs, called arguments, and return values.
* printf does return things, but we have not used it, so printing on the screen does not count as retunr
* get string has input and output
* so the programmer delegates the functionality to other functions, and we should not know how the functions did it
    - the programmer orchestrates.
* Sandbox can be used for multiple languages
* 
#### int.c

* stdio.h and cs50.h are header fles, means a file where the functions we use are created. or more precisely: the declaration of the functions to be used since the program has to know how a function is defined before using it (definition: arguments and retuen values), they are later coded in cs50.c and stdio.c
* in linux we can go up and down the commands that have been typed in
* floating points are numbers with decimal points
* since the decimal can float based on how big it is or precise

#### ints.c
* printf before printing can do some simple arithmetics
* *mod:* remainder %

#### floats.c
* like ints but shows float
* %f shows a few decimal points by default
* %.7f means show float but 7 decimal places
* Memory or RAM is a hardware where the programs that are running store they data, and it is of course finite.
* of we raise this to 50, we see numbers other than 0s
    - there is no bug here
    - HDD is permannet, but RAM is temporary
    - our memory is finite, so cannot hold infinite numbers and precisions
    - so computeers start cuttign some corners, and what we see for %.50f is as close as they can get
* This imprecision might be worrysome, if we do comparisons, but we can go around it for example by comparng instead of == for float numbers
    - More importantly: for exampel with rockets, slight imprecisions might add up
    - or in financial markets, there was a type of cunning to keep the money that the computers were ignoring
    - this imprecision should be addressed
* float takes 4 bytes, we have also double whic takes 8 bytes
* there is always a trade off between precision and space and processing power

#### parity.c and conditions.c answer.c cough0.c couch1.c cough2.c
* || implies or
* After copy pasting, we are probably not writing good code since it is difficult to maintain and many things should be changed if we want to change the behaviour
* everythig should be nicely indented so that it is better read
* we can also keep delegating and make puzzle pices and we do it by making functions
```C
#include <CS50.h>
#include <stdio.h>

int main(void)
{
    cough();
}
// Takes no inputs and does not return (so two voids)
void cough(void)
{
    print("cough\n");
}
```
* this gives error because cough has not been declared the before it was used.if we take the void cough(void) before main, the problem is solved
* **C is dumb and simply reads from top**
* so the main program gets getting pushed down further and further
* we want the main one be on top
* so we use a prototype for the function which is literally the very first line of it.

```C
#include <CS50.h>
#include <stdio.h>
void cough(void);
int main(void)
{
    cough();
}
// Takes no inputs and does not return (so two voids)
void cough(void)
{
    printf("cough\n");
}
```
* this is enough for it, so that it has seen its name
* So stdio and CS50 header files have the protype (declarations) of the functions that we use.
* so just the name and input and output.
* the actual ones are in cs50.c and stdio.c

#### cough3.c

```C
#include <CS50.h>
#include <stdio.h>
void cough(int);
int main(void)
{
    cough(3);
}
// Takes no inputs and does not return (so two voids)
void cough(int n)
{
    for(int i=0; i < n; i++){

    printf("cough\n");
    }    
}
```
* So now the cough function takes inputs adn cannot have void as argument
* just like we declare variables inside a function, we can also declare arguments
* So all the complexity of coughing has been factored in a puzzle piece.
* we or other programers should not necessarily know what is inside these puzzle pieces.

#### positive.c
* See the program in the course
* do{}while() first does the thing and then check the condition
```C
// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int(prompt);
    }
    while(n < 1);
    return n;
}
```
* This function has also a return.
* If we do int n in the while loop we are constanly declaring them
* in C variables have scope, they only exist in between curly braces, between which they were declared.
* This will be a prolem because we return it after the curly braces of the while..do
* so we declare it before and we do net give it a value. it has a garbage value.
* it is not baout local or global varibales, this is still local, but it has something to do with scope.

#### Overflow
* As said, we have limited space, so for exampe we have only 3 places for a decimal number, so after adding 1 to 999 we do not have enough space for 1000 and we get 000
* 111 plus one, we add the one, put the zero and carry the one and so on.\
* so if we have 3 bits, adding 1 to 7 would lead to 0
* RAM in finite and we might run into overflow and we have to think about it
* for example in a game they used 32 bits and the number was 4000000000

#### overflow.c
* comment is a nice summary of a otherwise cryptic looking code.
* sleep(int) is defined in unistd.h
* The program says that we overflowed and we ran out of bits.
* Y2K was this kind of bug: they were using 2 digits numbers for date so 99 turns to 00
* Another example: the generator of an aeroplane that would overflow and it goes into hibernate.
* underflow: 0000 to 1111 (the ghandi example)

## Shorts
### Command line
* we run Ubuntu
* we have used GUI up to now
* but we will be using the terminal window pretty frequently
* these do not work on windows since it is not unix based
* ls: short for list, a readout of all files and folders
* cd:  change directory, navigating between directories
* . : current ..: above current directory
* pwd: present working directory
* ctrl+l: clear the screen
* /home/.../ = ~ (home directory)
* cd : go home
* mkdir : make a directoty
* cp <sourcefile> <destination_file>
* cannot be used for directories that ae not empty: so recursively everything insode of it shoule be copied: cp -r <source_directory> <destination_directoty>
* -r is called a flag
* rm <file> to remove: be careful that it deletes for good, no recycyle bin ere
* rm -f : no confirmation
* rm -r : to delete a directory and everything inside of it.
* mv: move, it is also a kind of renaming

### Conditional statements
* make decisions and making forks, depending on values and what th euser enters
* {} if the boolean expression ios true, all the lines betwee curly braces will be executed, if not, it is skiped
* else will always happen if the boolean expression is not rue
* if {} else if {} else if {} .... else : only one of them happnes
* all of them are mutually exclusive
* we can also do non mutially excluse: if{} if {} if {} else{}
    - here only 3 and 4 are mutually exclusive
* else only binds to the nearest if
* switch: we ca use distict cases: **switch allows for enumeration of discrete cases**, instead of relying on boolean expressions
* we need to break, otherwise we will fall through
* the behaviour might be desiable, and all xases including and after the correct one will happen
* int x = (expr) ? 5 : 6; (this is an if..else but smaller and quicker)
    - so here if the expr is true, the value left of colon happens and else the one on the right
### Loops
* repeating saving copy an dpasting
* while (TRUE){} runs for ever: infinite loop
    - it can be broken with a break
* while (boolean expr){} runs as long as boolean expr is true
* do {} while() the lines after do will be done once
* for(int i = 0; i < 10; i++){} to run specific times
    - counter variable is set, this is executed. and we immediately evaluate the boolean
    - the boolean expression is checked
        + if true the body is executed
        + if false the body is not executed, for example if at first it was int i =15 and then i < 10, nothing would be executed
    - the counter is incremented and then the boolean expression is checked again, so the third field after the if-statement is executed after we reach the end of the {}
    - then we check if the boolean expression is true
    - Again for (start; expr; increment){}:
        + everything in start is executed which might be more than one
        + then the expr is checked, if true, we go though the look one tme
        + then we do what is in the increment part
        + then the expr is checked again
        + this is done until the expr is not true anymore
* All these can be interchanged

### operators
* = assignment to put a value inside a variable, with assignment, the value on the right is assigned to the left x=x * 5 first we do x*5 then put it in x. so x is overwritten
* "+ - * / % (modulus)": gives the remainder
    - can be used for example for a random number between  and 20: first we produce one randomly and then divide it by 20
* x *= 5 is equal x = x * 5 (worls for other operators too)
* x++ and x-- : incrementing and decrementing
* Boolean expressions:
    - used for comparing values
    - they boil down to TRUE or FALSE
    - every none zero value is TRUE
    - there are logical an drelational operators, but more on that later
    - logical: and (&&), or (|| at least one should be true), not (!)
    - relational: < > <= >=
    - equality == inequality !=
    - Do not misake assignment = and equality == 

### Data types
* modern languages do not need a specify a data type and they know by themselves
* but in C we need to declare it
* int: interger values
    - always takeup 4 bytes (32 bits)
    - positive and negative each take half the range so from -2^31 to 2^31-1
* unsigned int is not a seperate type, but unsigned is a *qualifier*: it modifies the data type
    * short and long and const are also qualifiers
* char: for single character. takes one byte -128 to 127
    - positive of this is mapped to charatcters on the keyborad through ASCII
* float: they are real numbers with decimal point in them. this is als 4 bytes
    - describing the range of float is not intuitive, for example if the integer part is big, we not have enough place for the floating part
* double is also for real numbers and has 8 bytes
    - we can be a lot more precise
* void is not a data type but it is a type, so we can define a variable of type void and assign a value to it
    - but functions can be void as return: does not return value like printf, it prints to the screen but no return
    - there are also functions the parameter list of which is void so they do not take any parameters
    - void is a palxce holder for nothing. but it is more comlicated than that.
* strings (series of characters) and bool (TRUE or FALSE) are not build in in C
* we have structs and typedefs etc, more on these later
* creating a variable: type name;
    - int number;
    - char letter;
    - int height, width;
    - declare variable only when needed so not all of them at the beginning
* after having declared a variable, we need to specify the type any more
    - if we do so, we run into problems
    - int number; // Declaration
    - number = 17; // Assignment
    - int second_number = 24; // Initialization
    - AGAIN: redeclaring runs into problems
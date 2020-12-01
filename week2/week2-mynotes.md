* There was a comppiler probldm, even though the cs.50.h was included, the compiler did not know strings and so on. the cs50 library should be linked:
    - cland hello.c -o hello -lcs50
    - make automates this
    - make is a build tool that helps us with building
 * compilation is the substraction, there are other leveles, for example our bins (zeros and ones) should be linked to cs50's
    1. **Preprocessing**: like the includes at the beginnig of a program. they are marked as #, this signals that these should be preporcessed. inside .h files there are defines and prototypes of functions. with #include<cs50.h> clang looks for cs.h (literally) grabs its content and puts it at teh top of out file. or stdio.h has printf
        * summary: # means that line should eb done fiorst and replaced by the actual headr file. it substitutes so that we do not need to do it manually
     1. **Compiling**: after preprocessing come actual compilation. source code turns into assembly. (like a.out). this is the lower level that CPU understands. C is an abstraction on assembly. This is what intel inside means
     2. **Assembling** turning the assemly into actual zeros and ones.
     3. **Linking** linking in other peoples zeros and ones. When we are writing a program that has libraries (other people's code cs50.c or stdio.c) so these also turn into zeros and ones (machine code or object code) and they are put together.
    * in linking only zeros and ones are linked and sometimes we get more than what we need

## buggy0.c
* We are trying to learn how to trouble shoot our programs using software
* Always scroll up in C programming.
* Here the header file is misiing whee printf is defined.
* in this course we can use help50 make buggy0 which helps us how to handle the problem
  * with highlight the problem is shown and below that is the advice (non-highlighted)
* The other problem is the missing semicolon
## Buggy2.c
* The problem compiles
* but we see 11 # instead of 10
* Now the program is working (no compiler error) but not doing what we want
  * help50 cannot be used
* in C and any language we can use print to diagnose.
* so instead od  (i = 0; i <= 1-; i++) we have i<10
* so bear in mind that teh programmers tend to count from 0
* Also we implemente printf("# %i", i) which shoes which i corresponds to which # and help us see that we are using 0 to 10 which is 11 times #
* **when in doubt, use printf**
* Also, it is not only about the goal, but also style matters. we see more visually what blocks are and what are they doing.
  * correctness
  * design
  * style
* look at the style guide
* there is also a tool that helps us to clean up: **style50**
## debugging tools
* help50
* printf
* style50
## RAM
* CPU is the brain
* But we have also RAM (random access memory)
* it is used whenever we run a program or open something
* it is different than the hard drive where things are stored permanently.
* RAM is powered are electrically and is not permanent
* when we open something it is copied onto ram
* it has less capacity, but it is much faster
* it is thematic: cheap and a lot of something and expensive but limited something else
* each chip has some bytes on it. (picture of the yellow mesh merged on the chip)
* when we creat a variable (char=1 byte) it goes literally ion one of the boxes.
* the boxes can be anywhere and the computer remembers where they are
## Arrays
* back to back memory or contigious memory is referred to an array
* this simple concept and capability (tp store things back to back) is very powerful
## score0
* we get a few scores to create a bar chart
* the moment we declare int, clang or computer gives us 4 bytes, but contigious
* we do 3 scores one by one.
* we use ASCII art: using ASCII charactes to visualize.
* to better program, first we **do just one score** to see if the whole concept is working
* seems like we are on our way, correctnesswise.
* now that we know taht we can print bars correctly, we start copy and pasting for other score
  * copy pasting is almost always bad.
* but it works for now, with opportunities for improvement
  * use a loop to do the same thing three times.
  * but the functionality of a function is to delegate functionallity and here by copy and pasting we wee doing that, so we can use a function.
* first we use a function to chart, we still have some copy and pasting, so not perfect yet but much better
* then chart was implicit: we can ether put chart at the top, or declare it before main. so that main remains at top. **prototype**
* we are still using 3 precoded scores so nmot many different scores
## scores2.c
* the answer to be flexible regarding the nmber of scores is the arrays
```C
int scores[3];
```
* this means: gives me a variable calles scores of the type integer, but give me three of them
* they are called collectively scores, so no single names.
```C
int scores[3];
for (int i = 0; i < 3; i++)
{
    // means store the ith value
    scores[i] = get_int("score %i", i +1);
}
```
* we are then by scores[i], indexing into an array
* the chart function has no idea that arrays are involved, so it stays the same
* but three (number of scores to be printed) is in few places
* so to change this laer, we need to change this in multiple places which will result in some logical error at some point.
* we could use a variale. but a special type: **magic number**
  * int COUNT = 5;
  * const int COUNT = 5;
  * This means that clang will make sure that we never change this
  * this is also defined capitalized which is human convention, it means it is global and it is special
* if we combine two for loops, after every input we see a chart, which is not wrong, but a design decision
## scores4.c
* we want to put more functionality.
* if a function gets and array as an input, it does not neet to know the size of the array.
```C
void chart(int count, int scores[])
```
* in C arrays do not have an inherent property that shows their length.
* so we also pass the second varibale which is count, the length of the array.
* so we have two nested for loops
* we should also have in mind that arrays can be passed to functions.
## string0.c
* strings are sequesnces of characters which is an array
* we can also index into a string just like it is an array.
* strlen() gives us the length of an string. (C's built in)
* %c to print a character in printf (place holder)
* the library is called string.h
* this would have been helpful in the problem set 1, credit
* string.h does not have a type called string!
  * so we still need cs50.h
* we do not need to use strlen every loop, because it does not change. so we can improve the design.
* we can build this in the loop itself
```C
for (i = 0, n = strlen(string); i < n; i++)
```
* these i and ns are only used inside the curly braces
* so i can be reused in later loops, adn vice versa, if we need them we should declare them in another way
## Null terminaltor
* so the string is stored contigious somewhere on the memory based on the decision of the compiler.
* other data is also on other places, so how do we know where our strings starts and where it ends?
* we know where it begins (variable with the name of the array in the first place) but we do not know whee it ends
* so where we use an array, we are secretly using an extra character, to show the end of the array.
* an array ends with a special character which is all zeros (8, since it is a character) or \0 NULL character
  * so a string with the length of 6 (like zamyla) is actually taking 7 bytes
## strlen.c
* the standard function strlen is just an abstraction that someone else did for us.
```C
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("Name: ");
     int n = 0;
     while (s[n] != '\0')
     {
         n++;
     }

    printf("The length of your name is %i\n", n); 
}
```
* So we store the string, and we know it is stored, the C way, which means it ends in \0, and we index through it till we get to \0 or 00000000
* so we are showing we know what is happening under the hood
* so all the functionality is actually simple
## ASCII0
* we get a string
* iterate over the lengh
* int c = (int) s[i] : casting
  * here we are converting the data types
  * so a character is 8 bits but presented in the context of characters, byte is also 8 bits but in the cintext of integer
  * it is completely context sensitive
* this is **explicit casting**
* but can also be done **implicitely**: the computer knows that characters are numbers
  * so first we can remove the casting
  * or even we can not define it into another varibale, but just print it using two different placeholders printf("%c %i", s[i], s[i])
## capitalize0.c
```C
if (s[i]) >= 'a' && s[i] <= 'z')
{
    printf("%c", s[i] - ('a' - 'A'));

}
else
{
    printf("%c", s[i]);
}
```
* we are asking is it lower case, but in programmer way with enough precision and required steps and minimm required assumptions
* the numbers have to do how the alphabet is laid out in ASCII
* math is cheap and eay in computer, so we can simply do it in our program using 'a' - 'A'
* else: it is capital and simply print it.
## capitalize1.c
* there is a function called islower which does this for us. ctype.h
* we can find out about this by google or someone told us that
* there is also a function toupper
* we can type man toupper in the command line and get info about it.
  * they tell us what header file is needed and the signature
  * (it is of type int but effectively return char)
* we read the manual and it tells us that it return capital, wehter small or capital
* CS50 has a more user frindly version also.
## argv0.c
* when we use make and clang, we use different command line arguments
* we can write c programs such that they get arguments from the user also
* up to now we have int main(void) which means it does not get input
* we can use:
```C
int main(int argc, string argv[])
{

}
```
* with this, we give arguments to the program
* it gets an array called argv (argument vector, vector means an array)
* argc (argument count) how many words are typed in the human prompt. the first being the name of the program
* so argv is an array of strings, and strings are an array of characters
## argv1.c
* so we iterate twice, once over all the strings, and second over each character in every string
## ciphering
* just coding is not a good way to cipher (like just sending ASCII codes 72 73 33 in stead of HI!)
  * because anyone has access to it
* so coding (mapping) is not ciphering
* this was used in WW2 which had a very big book behind it
  * this was decoded by the british
* Another example os from american war for independence which used 1 or 2 lanterns in case the brits were coming from either the sea or by land
* anyway, coding can be compromised easily if people get their hands on it
* instead we use sth more algorithmic: we need one more input called a key
  * first we turn I LOVE YOU into ASCII
  * we then use a secret key of 1, and we add that to every ASCII letter
  * then convert back to ASCII J MPWF ZPV
  * (all letter shifted by one)
  * now only the cod ebook is not enough, because there is a key in our minds too
  * to decrypt it, a crytoanalysis could be done: for exampe, we have spaces, and the fisrt one is one letter which will with high probability map to 'I'
  * There are two Ps, so there are aiou
  * there is probability involved and makes it more secure
  * because apart from the common known ASCII (or any other type of code) there is a value agreed between two parties.
* caesar used a cipher: substitution cipher: a is b, b is c etc 
## exit.c
* other way to signal error: return values that are signaled by the computers
* main returns can be seen
* echo $?
* this shows what main has returned
* main autamatically returns 0 if everything has been going well, even if it is not coded in
* which is the same as error some number when we have an error
## finding 50
* array can be used to solve problems more algorithmically
* the computer can do one thing at a time
* in the algorithms descussed before, there was an assumption that the phone book was sorted algorithmically
* first to find something, and with no information, we can only guess
* but if they are sorted we can do better
## sorting on stage
* how we sort?
* different ways that the students wearing shirts wit different numbers on used:
  * first everyone just found their chair and went on to sit on it: **index location**
  * it is always important to ask how eficient each algoritm is
  * first we see just two neighbours and sort them, once from left to right
  * the numbers **bubble** their way
  * each time a number finds its plca, we do not need to do them anymore
  * we pick a number as the smallest and look to see if there is something smaller than that, if yes we replace tem
  * then we pick 4 again and keep looking, we see 2 and then we start comparing everyone with 2, if no one was smaller, we replace 4 and 2
  * here we are selecting smallest one, but we are not going back
## bubble sort
* pair by pair sort fixing tiny mistakes
* n-2 because there are from 0 to n and we compare i and i + 1
## selection sort
* select the smallest and put them in their place (by swaping), and then later forget about them
## computational comlexity
* the two ways has give or take the sdame number of steps
* in selection sort: 
  * first we have n-1 comparisons
  * then we have n -2 because the smallest is in its place
  * (n-1)+(n-2)+....+1= n(n-1)/2 in the order of n^2 (this dominates as n gets larger and larger)
  * O(n^2)
* big O is a symbol in CS and math to describe (with a wave of the hand) how fast or slow the algorithm is
* other algorithms:
  * one page or two pages at a time are almost the same and linear O(n)
  * dividing is like log
  * just open phone book: constant
## merge sort
* we need few more arrays
* the comparisons were time consuming
* first we sort half
* then also half that
* until we are on only one block
* then we merge the sorted halves (each block is sorted by itself)
* but we need an extra array
* so we then merge two sorted arrays of two elements into one array of 4 and sort it
* we had 8 numbers and they had to move 3 times (2^3): a logarithm
* n numbers moved logn times = nlog(n)
## conparing sorts visually
* 
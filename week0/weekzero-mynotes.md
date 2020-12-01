* programming is a tool we use, but the course is more about solving problems.
* What is problem solving: using algorithms based on the input and produce the output
* Input and outputs are in binary (because of the underlying electrical properties:on or off)
* If we use only the number of fingers of out hand to represent data (unary, there is or there is not) we can show up to nuber 5, but if the pattern is important (binary) we can go up to 32
* 123 in decimal system: 3 in 1's place, 2 in 10s place etc.
* in CS, instead of powers of 10, we use powers of 2
* each place is called a bit
* this "numbers" can represent many things, like numbers themselves, or different type of data in different contexts.
* this needs a **mapping**: like ASCII for letters, also graphics.
* ASCII is 8 bits, but it cannot represent all types of languages, so it has been replaced by unicode
* Another mappng is RGB for combining collors out of number
* just one bit is not enough and we have the concept of byte which is 8 bits (byte us a unit to manage bits)
* All of these are examples of abstraction.
* Computer programs, based on the context of their code, know which mapping should be used.
* there are a lot of lower level implementation details that have been solved by people before us so that now  we can work on application level and solve problems that matter to us.
  * This is called abstraction, which means how low level implementation is simplified or taken for granted for usage at higher level or aplication level.
* So for example videos are abstraction over pictures, pictures abstraction over pixelsm and pixels abstraction over bytes.
* Algorithm is inside which solves the problem: Step by step instructions for solving problems.
* Computers do only what we tell them to do and cannot read between lines: They are not as forgiving!
* So it is about breaking the problems into their consisting steps
* All types of probblems might arise when computers run into undefined scenarios
* A bug is a mistake, a human error in the code section.
* On finding a name in a phonnebook, we can keep doing the same thing, and the problem stays the same, in only shrinks. this type of algorithm is called recursive.
* Ways to find a name in the phone book:
  * Page by page which is linear and means that the dificulty icreases lineary with the size of the problem
  * two pages at a time, still linear, buthalf of the previous one
  * open it in the middle (assuming it is organized alphabetically) and decide wether it is on the left or the right. this is logarithmic, meaning that incresing the size from 1000 to 2000 needs only one extra step.
* 
* pseudocode: code with english syntax, no particular programming language,
* in code we have **functions (or actions)** that do  stuff, and **boolean expression (answer to questions)** which are true or false, which is in accordance to the yes/no and binary situation of the whole system and also the **questions (if/else etc.)** which lead to different paths, finally words that lead to **cycles like loos and gotos**
* syntatic expressions might get in the way of intellectual act of coding and problem solving, so for the fist session scratch is used which is a graphical way of coding.
* scratch and also other programs that we will be using in the future have the following properties:
  * variables: the ability to store data
  * threads: the ability to do multiple things
  * event: te ability to respond to changes in the program in inputs
* We can do many stuff in scratch:
  * we can run two threads simultaniously, so one event follows of the space key is pressed or not, which sets a variable to 1 or zero if it is pressed a seal start to say stuff and if pressed again, it shut up
  * Also one thread can broadcast an event and other parts of the program can respond to it upon receiveing it.
* one sign of bad programming: when you are repeating your self and copy and pasting yourself (DRY: don't repeat yourself) so isntead use functions and loops
* functions are also a way of abstracting
* collns of code that can be sued by us is called a library
# Roman Numeral Calculator
For this programming exercise, you will be creating a library which will allow
the addition and subtraction of Roman numerals. Once your solution is complete,
please provide your solution as a Git repository (publicly available via Github
or Bitbucket). Please include within your repository, all source and test code.

This exercise is based on the Roman Numeral Calculator Kata at
http://bit.ly/1VfHqlj.

Please submit your test driven solution via a public Git repository
(github/bitbucket).

### The solution will be reviewed for:
* Test coverage
* Test Driven Development
* Algorithm Usage
* Code structure
* Use of source control
* Completeness of the overall solution

### The environment for this programming exercise must utilize:
* Ubuntu Linux 14.04
* The C programming language
* GNU GCC compiler tool chain
* GNU Make
* Check unit testing framework ( https://libcheck.github.io/check/ )
* git

## Roman Numeral rules:
* Roman numerals consist of the following letters:
  I, V, X, L, C, D, and M which mean
  one, five, ten, fifty, hundred, five hundred and one thousand respectively.
* An example would be "XIV" + "LX" = "LXXIV"
* Numerals can be concatenated to form a larger numeral ("XX" + "II" = "XXII")
  as long as the value of the first letter of the second part is less than the
  value of the last letter of the first part. ("XXI" + "V" is "XXVI", not
  "XXIV").
* If a lesser numeral is put before a bigger it means subtraction of the lesser
  from the bigger ("IV" means four, "CM" means ninehundred).
    * only a single lesser numeral is allowed before a bigger numeral
    * I is allowed before only V and X
    * X is allowed before only L and C
    * C is allowed before only D and M
    * V, L, and D are not allowed before bigger numerals
* If the numeral is I, X or C you can't have more than three consecutively
  ("II" + "II" = "IV" not “IIII”).
* If the numeral is V, L or D you can't have more than one consecutively
  ("D" + "D" = "M" not “DD”)
* The maximum roman numeral is 3999 (MMMCMXCIX)

## Stories
### User Story: Addition
As a Roman bookkeeper, I want to be able to add two numbers together;
so that I can do my work faster with fewer mathematical errors.
### User Story: Subtraction 
As a Roman bookkeeper, I want to be able to subtract one number from another;
so that I can do my work faster and with fewer mathematical errors.

---

# Installation

The following instructions work for Ubuntu 14.04, particularly
for booting the Ubuntu 14.04.5 64-bit desktop installation DVD[1] as
a live distro in a virtual machine with 2 GB of RAM.

    sudo apt-get -y install git
    git clone https://github.com/james-prior/pillar-kata-roman-numeral-calculator.git
    cd pillar-kata-roman-numeral-calculator
    git checkout master
    ./do-everything.sh

---

# The journey

I tried and abandoned multiple approaches. It was a fun.

## Python library:

    I started out playing with Python and tried several
    approaches. I stumbled across using a regular expression
    (regex) to parse Roman numerals. That made the code simple.
    Later I used the idea of using a regex in the C code. I don't
    think I would have thought of using a regex in C without
    having used it in Python first, so playing with Python was
    useful.

    The library can be used from Python REPL. For example:

        (env) kata@pillar:~/kata-roman-numeral-calculator$ git co 8e62fe5
        HEAD is now at 8e62fe5... roman.py: Refactor creation of pattern.
        (env) kata@pillar:~/kata-roman-numeral-calculator$ python
        Python 3.5.2 (default, Nov 23 2017, 16:37:01) 
        [GCC 5.4.0 20160609] on linux
        Type "help", "copyright", "credits" or "license" for more information.
        >>> from roman import Roman
        >>> Roman('I')
        Roman('I')
        >>> Roman('I') + Roman('III')
        Roman('IV')
        >>> Roman('I') + Roman('III') + Roman('M')
        Roman('MIV')
        >>> Roman('I') + Roman('III') + Roman('M') - Roman('V')
        Roman('CMXCIX')
        >>> Roman('I') - Roman('I')
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
          File "/home/kata/kata-roman-numeral-calculator/roman.py", line 79, in __sub__
            raise OverflowError
        OverflowError
        >>> Roman('MMMCMXCVIII') + Roman('I')
        Roman('MMMCMXCIX')
        >>> Roman('MMMCMXCVIII') + Roman('I') + Roman('I')
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
          File "/home/kata/kata-roman-numeral-calculator/roman.py", line 73, in __add__
            raise OverflowError
        OverflowError
        >>> 
        (env) kata@pillar:~/kata-roman-numeral-calculator$ 

        I never bothered to commit a calculator program that used
        my Python library.

    8580e2b 2017-11-06 21:29:29 -0500

        Somewhat functional approach for creating Roman object.
        It is reasonably readable, but I wanted something better.

    48b1750 2017-11-06 22:38:37 -0500 (jp-failed-experiment-1)

        Refactored. Parses in reverse order, simplified code,
        but I wanted something better yet.

    8e62fe5 2017-11-07 23:34:27 -0500 (python-regex-best)

        Used regex to parse Roman numerals.
        That greatly simplified the code. This was a game changer.
        I liked this approach so much I later used it for C code.

        8f9bdd0 2017-11-07 03:41:07 -0500

            Can mix math between Roman and int.
            This is nice, but a Roman bookkeeper would not have
            benefitted from this, so I dropped later in 10fe267
            because of YAGNI.

        dd59522 2017-11-15 11:54:11 -0500 (python-show-regex)

            Have Python show its regex, to copy into C code.

    07d8259 2017-11-15 11:43:08 -0500 (jp-dev4)

        Use complicated logic to parse Roman numerals instead of regex.

            This is classic approach for microcontrollers with
            little resources, like 8-bit microcontrollers.
            Of course, little 8-bit microcontrollers would not
            even be able to run Python.

            If one is using Linux, one has plenty of memory and
            CPU, so I would use regex approach for Linux.

## C library:

    Used autotools. It works and is portable, but is terribly
    complicated.

    cdcb8a5 2017-11-14 23:15:29 -0500

        Even though it is written in C, it had an object-oriented
        approach. It used complicated logic for parsing.
        I wanted something better.

    82cb480 2017-11-26 18:05:41 -0500

        Simplified validation of Roman numerals by using a
        regular expression instead of complicated logic.
        That part was great.

        Still has object oriented attitude: creating and
        destroying objects was too tedious.
        I wanted something better.

    7e0e097 2017-11-27 14:55:55 -0500

        Changed the API to be kind of like sprintf, where caller
        gives pointer to destination (instead of object oriented
        approach). This was an improvement, but I wanted
        something simpler.

    4488def 2017-11-28 02:33:37 -0500

        Simplified API to use a shared static buffer for returned
        Roman numerals. This is the simplest overall.

## C demo-program

    This little program demonstates that the library works.

    This was done completely separately from the library to show
    that it was using the roman package installed on the system.
    Hand edited Makefile was used instead of autotools monster.
    Makefile is simple, but not as portable was with autotools
    for library.

    b806b5a 2017-11-29 20:05:53 -0500

---

# Footnotes

[1] The image used was:

    -rw-r-----. 1 pillar pillar 1104052224 Aug  3  2016 ubuntu-14.04.5-desktop-amd64.iso
    MD5SUMS:0abc200fd4b84a1e8881287d70dfb822 *ubuntu-14.04.5-desktop-amd64.iso
    SHA1SUMS:a782741d92cb1abbed978a41dcca5244435e7a58 *ubuntu-14.04.5-desktop-amd64.iso
    SHA256SUMS:f5ce20686a2f3201f04a309d04171ee15757f00954b33b87f3f1d36b3b0f5356 *ubuntu-14.04.5-desktop-amd64.iso

# Roman Numeral Calculator
For this programming exercise, you will be creating a library which will allow the addition and subtraction of Roman numerals. Once your solution is complete, please provide your solution as a Git repository (publicly available via Github or Bitbucket). Please include within your repository, all source and test code.

This exercise is based on the Roman Numeral Calculator Kata at http://bit.ly/1VfHqlj.

Please submit your test driven solution via a public Git repository (github/bitbucket).

### The solution will be reviewed for:
* Test coverage
* Test Driven Development
* Algorithm Usage
* Code structure
* Use of source control
* Completeness of the overall solution

### The environment for this programming exercise must utilize:
* Ubuntu Linux 16.04 LTS
* The C programming language
* GNU GCC compiler tool chain
* GNU Make
* Check unit testing framework ( https://libcheck.github.io/check/ )
* git

## Roman Numeral rules:
* Roman numerals consist of the following letters: I, V, X, L, C, D, and M which mean one, five, ten, fifty, hundred, five hundred and one thousand respectively.
* An example would be "XIV" + "LX" = "LXXIV"  
* Numerals can be concatenated to form a larger numeral ("XX" + "II" = "XXII").
* If a lesser numeral is put before a bigger it means subtraction of the lesser from the bigger ("IV"  means four, "CM" means ninehundred).
* If the numeral is I, X or C you can't have more than three ("II" + "II" = "IV" not “IIII”).
* If the numeral is V, L or D you can't have more than one ("D" + "D" = "M" not “DD”)
* The maximum roman numeral is 3999 (MMMCMXCIX)  

## Stories
### User Story: Addition
As a Roman bookkeeper, I want to be able to add two numbers together; so that I can do my work faster with fewer mathematical errors.  
### User Story: Subtraction 
As a Roman bookkeeper, I want to be able to subtract one number from another; so that I can do my work faster and with fewer mathematical errors.

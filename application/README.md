# Roman Numeral Calculator

This directory is for a little command line program 'computator'
to demonstrate the use of the Roman numeral library. It is in a
different directory than the library stuff, to demonstrate that
it is using the library as installed on the system.

Everything here is much much lighter than the heavy autotools
stuff used for the making and testing the library.

## Prerequisites

inotify stuff?
math library?
compiler?
check!
gcc

## Test

This relies on the roman library to be installed on the system,
so do the following after creating the roman library and 
installing it on the system.
Execute from the same directory that this README.md file is in:

    while inotifywait -r -e modify src tests; do
        make
        make check
    done

It automatically (re)runs the tests whenever a file in the src
and tests directories changes. This is handy whether the change
is from saving from an editor, or by looking at various commit
with git checkout commands.

## Compile

This relies on the roman library to be installed on the system,
so do the following after creating the roman library and 
installing it on the system.
Execute from the same directory that this README.md file is in:

    make

## Use

The program accepts roman numerals as command line arguments.
Roman numerals prefixed with '-' are subtracted.
A line is output for each command line argument,
repeating the argument and the running sum.
If there is a error at any point, "ERRATUM" appears
in place of the running sum and the program stops.
For example:

    kata@pillar:~/kata-roman-numeral-calculator/application$ src/computator I II III IV V VI -XX MMMCMXCVIII I
    I I
    II III
    III VI
    IV X
    V XV
    VI XXI
    -XX I
    MMMCMXCVIII MMMCMXCIX
    I ERRATUM
    kata@pillar:~/kata-roman-numeral-calculator/application$ 

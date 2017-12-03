# Roman Numeral Calculator

This directory is for a little command line program 'computator'
that demonstrates the use of the Roman numeral library. It is in
a different directory than the library stuff, to demonstrate that
it is using the library as installed on the system.

Everything here is much much lighter than the heavy autotools
stuff used for the library. A downside of that is lessened
portability. This is known to work with Ubuntu 14.04.5 LTS.

This program relies on the roman library to be installed on the
system, so do the following after creating the Roman numeral
library and installing it on the system.

Any commands shown below should be executed in the same directory
as this file.

## Prerequisites

The library must already be installed.

## Test

    make check

The loop below automatically (re)runs the tests whenever a file
in the src and tests directories change. This is handy whether
the change is from saving from an editor, or by browsing various
commits with git checkout commands. Execute:

    while inotifywait -r -e modify src tests; do
        make
        make check
    done

## Compile

    make

## Use

The program accepts roman numerals as command line arguments.
Roman numerals prefixed with '-' are subtracted.
A line is output for each command line argument,
repeating the argument and the running sum.
If there is a error at any point,
"ERRATUM" appears for the running sum and the program stops.
For example:

    kata@pillar:~/kata-roman-numeral-calculator/demo-program$ src/computator I II III IV V VI -XX MMMCMXCVIII I
    I I
    II III
    III VI
    IV X
    V XV
    VI XXI
    -XX I
    MMMCMXCVIII MMMCMXCIX
    I ERRATUM
    kata@pillar:~/kata-roman-numeral-calculator/demo-program$ 

## Do everything

To compile, test, and run program, execute the following.

    ./do-everything.sh

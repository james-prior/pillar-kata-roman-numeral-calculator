import pytest

from roman import Roman

'''
copied from README.md for todo list

# Roman Numeral Calculator
For this programming exercise, you will be creating a library which will allow
the addition and subtraction of Roman numerals. Once your solution is complete,
please provide your solution as a Git repository (publicly available via Github
or Bitbucket). Please include within your repository, all source and test code.

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
'''

'''
'''

int_string_romans = '''
    1 I
    2 II
    3 III
    4 IV
    5 V
    6 VI
    7 VII
    8 VIII
    9 IX
    10 X
    11 XI
    12 XII
    13 XIII
    14 XIV
    15 XV
    16 XVI
    17 XVII
    18 XVIII
    19 XIX
    20 XX
    30 XXX
    40 XL
    41 XLI
    44 XLIV
    49 XLIX
    50 L
    68 LXVIII
    89 LXXXIX
    99 XCIX
    100 C
    199 CXCIX
    200 CC
    300 CCC
    383 CCCLXXXIII
    499 CDXCIX
    500 D
    888 DCCCLXXXVIII
    999 CMXCIX
    1000 M
    1883 MDCCCLXXXIII
    2000 MM
    3000 MMM
    3883 MMMDCCCLXXXIII
    3999 MMMCMXCIX
'''.strip().split('\n')
expected_roman_strings = (s.strip().split() for s in int_string_romans)
roman_expected_ints = [
    (roman, int(x))
    for x, roman in expected_roman_strings]
@pytest.mark.parametrize('roman, expected', roman_expected_ints)
def test_known_number_returns_expected(roman, expected):
    assert expected == Roman(roman).get_value()


bad_romans_expected_errors = (
    ('', ValueError),
    ('IL', ValueError),
    ('XD', ValueError),
    ('IIII', ValueError),
    ('IIIII', ValueError),
    ('VV', ValueError),
    ('CCCC', ValueError),
    ('DD', ValueError),
    ('MMMM', ValueError), # too big value
    ('ONE', ValueError), # not roman
)
@pytest.mark.parametrize(
    'bad_roman, expected_exception', bad_romans_expected_errors)
def test_bad_roman_raises_expected_exception(
        bad_roman, expected_exception):
    with pytest.raises(expected_exception):
        _ = Roman(bad_roman)


'''
    100 C
    199 CXCIX
    200 CC
    300 CCC
    383 CCCLXXXIII
    499 CDXCIX
    500 D
    888 DCCCLXXXVIII
    999 CMXCIX
    1000 M
    1883 MDCCCLXXXIII
    2000 MM
    3000 MMM
    3883 MMMDCCCLXXXIII
    3999 MMMCMXCIX
'''
int_string_romans = '''
    1 I
    2 II
    3 III
    4 IV
    5 V
    6 VI
    7 VII
    8 VIII
    9 IX
    10 X
    11 XI
    12 XII
    13 XIII
    14 XIV
    15 XV
    16 XVI
    17 XVII
    18 XVIII
    19 XIX
    20 XX
    30 XXX
    40 XL
    41 XLI
    44 XLIV
    49 XLIX
    50 L
    68 LXVIII
    89 LXXXIX
    99 XCIX
'''.strip().split('\n')
number_expected_roman_strings = (
    s.strip().split() for s in int_string_romans)
int_expected_roman_numerals = [
    (int(x), roman)
    for x, roman in number_expected_roman_strings]
@pytest.mark.parametrize(
    'number, expected_roman_numeral', int_expected_roman_numerals)
def test_str_returns_expected(number, expected_roman_numeral):
    assert expected_roman_numeral == str(Roman(number))

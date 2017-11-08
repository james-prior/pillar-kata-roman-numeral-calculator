import re
from collections import Counter

class Roman:
    minimum = 1
    maximum = 3999

    def _make_list_of_roman_digits(s):
        return [''] + s.split()

    roman_units = _make_list_of_roman_digits('I II III IV V VI VII VIII IX')
    roman_tens = _make_list_of_roman_digits('X XX XXX XL L LX LXX LXXX XC')
    roman_hundreds = _make_list_of_roman_digits('C CC CCC CD D DC DCC DCCC CM')
    roman_thousands = _make_list_of_roman_digits('M MM MMM')

    def _make_value_of_roman_digits(roman_digits, scaler):
        return {
            roman_digit: i * scaler
            for i, roman_digit in enumerate(roman_digits)
            if i > 0
        }

    value_of_roman_thousands = _make_value_of_roman_digits(
        roman_thousands, 1000)
    value_of_roman_hundreds = _make_value_of_roman_digits(roman_hundreds, 100)
    value_of_roman_tens = _make_value_of_roman_digits(roman_tens, 10)
    value_of_roman_units = _make_value_of_roman_digits(roman_units, 1)
    value_dicts = (
        value_of_roman_thousands,
        value_of_roman_hundreds,
        value_of_roman_tens,
        value_of_roman_units,
    )
    value_of_roman_digits = {}
    for d in value_dicts:
        value_of_roman_digits.update(d)

    thousands_pattern = '(?P<value_of_roman_thousands>' + '|'.join(value_of_roman_thousands) + ')?'
    hundreds_pattern = '(?P<value_of_roman_hundreds>' + '|'.join(value_of_roman_hundreds) + ')?'
    tens_pattern = '(?P<value_of_roman_tens>' + '|'.join(value_of_roman_tens) + ')?'
    units_pattern = '(?P<value_of_roman_units>' + '|'.join(value_of_roman_units) + ')?'
    pattern = re.compile(
        '^' +
        thousands_pattern +
        hundreds_pattern +
        tens_pattern +
        units_pattern +
        '$')

    def __init__(self, roman_numeral_or_x):
        try:
            self.value = int(roman_numeral_or_x)
        except ValueError:
            roman_numeral = roman_numeral_or_x
        else:
            if self.minimum <= self.value <= self.maximum:
                return
            raise ValueError

        m = re.match(self.pattern, roman_numeral)
        if not m:
            raise ValueError
        groups = m.groupdict()
        self.value = sum(
            self.value_of_roman_digits.get(s, 0)
            for s in groups.values()
        )
        if self.value < self.minimum:
            raise ValueError

    def get_value(self):
        return self.value

    def __add__(self, other):
        value = self.value + other.value
        if value > self.maximum:
            raise OverflowError
        return Roman(value)

    def __sub__(self, other):
        value = self.value - other.value
        if value < self.minimum:
            raise OverflowError
        return Roman(value)

    def __str__(self):
        value = self.value
        reversed_digits = map(int, reversed(str(self.value)))
        roman_dicts = [
            self.roman_units,
            self.roman_tens,
            self.roman_hundreds,
            self.roman_thousands,
        ]
        terms = [
            d[i]
            for i, d in zip(reversed_digits, roman_dicts)
        ]
        return ''.join(reversed(terms))

    def __repr__(self):
        return "{name}({value})".format(
            name=self.__class__.__name__,
            value=repr(str(self)),
        )

import re
from collections import Counter

class Roman:
    minimum = 1
    maximum = 3999

    thousands = {
        'M': 1000,
        'MM': 2000,
        'MMM': 3000,
    }
    hundreds = {
        'C': 100,
        'CC': 200,
        'CCC': 300,
        'CD': 400,
        'D': 500,
        'DC': 600,
        'DCC': 700,
        'DCCC': 800,
        'CM': 900,
    }
    tens = {
        'X': 10,
        'XX': 20,
        'XXX': 30,
        'XL': 40,
        'L': 50,
        'LX': 60,
        'LXX': 70,
        'LXXX': 80,
        'XC': 90,
    }
    units = {
        'I': 1,
        'II': 2,
        'III': 3,
        'IV': 4,
        'V': 5,
        'VI': 6,
        'VII': 7,
        'VIII': 8,
        'IX': 9,
    }
    combined = {}
    for d in thousands, hundreds, tens, units:
        combined.update(d)

    def _make_digits_list_from_dict(d, multiplier):
        t = {number: roman for roman, number in d.items()}
        a = []
        for i in range(10):
            a.append(t.get(multiplier * i, ''))
        return a

    roman_units = _make_digits_list_from_dict(units, 1)
    roman_tens = _make_digits_list_from_dict(tens, 10)
    roman_hundreds = _make_digits_list_from_dict(hundreds, 100)
    roman_thousands = _make_digits_list_from_dict(thousands, 1000)

    thousands_pattern = '(?P<thousands>' + '|'.join(thousands) + ')?'
    hundreds_pattern = '(?P<hundreds>' + '|'.join(hundreds) + ')?'
    tens_pattern = '(?P<tens>' + '|'.join(tens) + ')?'
    units_pattern = '(?P<units>' + '|'.join(units) + ')?'
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
            # raise KeyError
            raise ValueError

        m = re.match(self.pattern, roman_numeral)
        if not m:
            raise ValueError
        groups = m.groupdict()
        self.value = sum(
            self.combined.get(s, 0)
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

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

    # def _make_value_of_roman_digits(roman_digits, scaler):
    #     return {
    #         roman_digit: i * scaler
    #         for i, roman_digit in enumerate(roman_digits)
    #         if roman_digit
    #     }

    # value_of_roman_thousands = _make_value_of_roman_digits(
    #     roman_thousands, 1000)
    # value_of_roman_hundreds = _make_value_of_roman_digits(roman_hundreds, 100)
    # value_of_roman_tens = _make_value_of_roman_digits(roman_tens, 10)
    # value_of_roman_units = _make_value_of_roman_digits(roman_units, 1)
    # value_dicts = (
    #     value_of_roman_thousands,
    #     value_of_roman_hundreds,
    #     value_of_roman_tens,
    #     value_of_roman_units,
    # )
    # value_of_roman_digits = {}
    # for d in value_dicts:
    #     value_of_roman_digits.update(d)

    # def _make_digits_pattern(roman_digits):
    #     return '(' + '|'.join(roman_digits) + ')?'

    # pattern = re.compile(
    #     '^' +
    #     ''.join(map(_make_digits_pattern, value_dicts)) +
    #     '$')

    value_of_roman_letters = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    max_run_lengths_of_roman_letters = {
        'I': 3,
        'V': 1,
        'X': 3,
        'L': 1,
        'C': 3,
        'D': 1,
        'M': 3, # not specified in README.md, but works nice
    }
    valid_subtractive_value_pairs = {
        (1, 5),
        (1, 10),
        (10, 50),
        (10, 100),
        (100, 500),
        (100, 1000),
    }

    def __init__(self, roman_numeral_or_int):
        if not roman_numeral_or_int:
            # raise KeyError
            raise ValueError
        try:
            self.value = int(roman_numeral_or_int)
        except ValueError:
            roman_numeral = roman_numeral_or_int
        else:
            if self.minimum <= self.value <= self.maximum:
                # self.value = 0
                return
            # raise KeyError
            raise ValueError

        value = 0
        old_letter_value = 0
        n = 0
        sign = +1
        for letter in reversed(roman_numeral):
            try:
                letter_value = self.value_of_roman_letters[letter]
            except KeyError:
                # raise KeyError
                raise ValueError
            if letter_value != old_letter_value:
                n = 0
            n += 1
            if n > self.max_run_lengths_of_roman_letters[letter]:
                # raise KeyError
                raise ValueError
            if sign == -1 and n > 1:
                # raise KeyError
                raise ValueError
            sign = -1 if letter_value < old_letter_value else +1
            if (
                    sign == -1 and
                    (letter_value, old_letter_value)
                    not in self.valid_subtractive_value_pairs):
                # raise KeyError
                raise ValueError
            value += sign * letter_value
            old_letter_value = letter_value
        self.value = value
        # self.value = None
    #     try:
    #         self.value = int(roman_numeral_or_x)
    #     except ValueError:
    #         roman_numeral = roman_numeral_or_x
    #     else:
    #         if self.minimum <= self.value <= self.maximum:
    #             return
    #         raise ValueError

    #     m = re.match(self.pattern, roman_numeral)
    #     if not m:
    #         raise ValueError
    #     self.value = sum(
    #         self.value_of_roman_digits[s]
    #         for s in m.groups()
    #         if s
    #     )
    #     if self.value < self.minimum:
    #         raise ValueError

    def get_value(self):
        return self.value

    def __add__(self, other):
        value = self.value + other.value
        if value > self.maximum:
            # raise KeyError
            raise OverflowError
        return Roman(value)

    def __sub__(self, other):
        value = self.value - other.value
        if value < self.minimum:
            # raise KeyError
            raise OverflowError
        return Roman(value)

    def __str__(self):
        roman_dicts = (
            self.roman_units,
            self.roman_tens,
            self.roman_hundreds,
            self.roman_thousands,
        )

        reversed_digits = map(int, reversed(str(self.value)))
        roman_digits = [
            d[i]
            for i, d in zip(reversed_digits, roman_dicts)
        ]
        # return 'fail army'
        return ''.join(reversed(roman_digits))

    def __repr__(self):
        # return 0
        return "{name}({value})".format(
            name=self.__class__.__name__,
            value=repr(str(self)),
        )

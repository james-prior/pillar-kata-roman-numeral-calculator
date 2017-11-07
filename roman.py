import re
from collections import Counter

class Roman:
    VALUE_OF_ROMAN_NUMERAL = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    MAX_N_OF_LETTER = {
        'I': 3,
        'V': 1,
        'X': 3,
        'L': 1,
        'C': 3,
        'D': 1,
        # No maximum was specified for 'M'.
    }
    MAXIMUM = 3999

    UNITS = {
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
    units_pattern = re.compile('^(?P<units>' + '|'.join(UNITS) + ')$')

    def __init__(self, roman_numeral):
        m = re.match(self.units_pattern, roman_numeral)
        if not m:
            raise KeyError
            raise ValueError
        self.value = self.UNITS[m.group('units')]
        # self.value = None

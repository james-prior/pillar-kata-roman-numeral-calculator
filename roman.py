import re
from collections import Counter

class Roman:
    MAXIMUM = 3999

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
    thousands = {
        'M': 1000,
        'MM': 2000,
        'MMM': 3000,
    }
    combined = {}
    for d in units, tens, hundreds, thousands:
        combined.update(d)

    units_pattern = '(?P<units>' + '|'.join(units) + ')?'
    tens_pattern = '(?P<tens>' + '|'.join(tens) + ')?'
    hundreds_pattern = '(?P<hundreds>' + '|'.join(hundreds) + ')?'
    thousands_pattern = '(?P<thousands>' + '|'.join(thousands) + ')?'
    pattern = re.compile(
        '^' +
        thousands_pattern + hundreds_pattern +
        tens_pattern + units_pattern +
        '$')

    def __init__(self, roman_numeral):
        m = re.match(self.pattern, roman_numeral)
        if not m:
            # raise KeyError
            raise ValueError
        groups = m.groupdict()
        self.value = sum(
            self.combined.get(s, 0)
            for s in groups.values()
        )
        # self.value = None

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
    def __init__(self, roman_numeral):
        if not roman_numeral:
            raise ValueError

        reversed_roman_numeral = list(reversed(roman_numeral))
        previous_reversed_roman_numeral = (
            ['after end'] + reversed_roman_numeral[:-1])
        next_reversed_roman_numeral = (
            reversed_roman_numeral[1:] + ['before beginning'])

        value = 0
        n = 0
        letter_value = 0
        for previous_letter, letter, next_letter in zip(
                previous_reversed_roman_numeral,
                reversed_roman_numeral,
                next_reversed_roman_numeral):
            n += 1
            if previous_letter != letter:
                previous_letter_value = letter_value
                try:
                    letter_value = self.VALUE_OF_ROMAN_NUMERAL[letter]
                except KeyError:
                    raise ValueError
                sign = +1 if previous_letter_value < letter_value else -1
            if next_letter != letter:
                if n > self.MAX_N_OF_LETTER.get(letter, n):
                    raise ValueError
                value += sign * n * letter_value
                n = 0

        if value > self.MAXIMUM:
            raise ValueError

        self.value = value
        return

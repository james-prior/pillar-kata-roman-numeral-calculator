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
    def __init__(self, roman_numeral):
        letter_counts = Counter(list(roman_numeral))
        for letter, n in letter_counts.items():
            if n > self.MAX_N_OF_LETTER.get(letter, n):
                raise ValueError
            
        self.value = sum(
            self.VALUE_OF_ROMAN_NUMERAL[letter]
            for letter in roman_numeral)

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
    def __init__(self, roman_numeral):
        self.value = sum(
            self.VALUE_OF_ROMAN_NUMERAL[letter]
            for letter in roman_numeral)

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
        if any(
                letter not in self.VALUE_OF_ROMAN_NUMERAL
                for letter in roman_numeral):
            raise ValueError

        next_letters = list(roman_numeral)[1:] + ['past end']
        end_of_runs = [
            letter != next_letter
            for letter, next_letter in zip(roman_numeral, next_letters)]

        letter_counts = []
        n = 0
        for letter, end_of_run in zip(roman_numeral, end_of_runs):
            n += 1
            if end_of_run:
                letter_counts.append((letter, n))
                n = 0

        if any(
                n > self.MAX_N_OF_LETTER.get(letter, n)
                for letter, n in letter_counts):
            raise ValueError

        letter_values = [
            self.VALUE_OF_ROMAN_NUMERAL[letter]
            for letter, _ in letter_counts]
        next_letter_values = letter_values[1:] + [0]
        signs = [
            +1 if value > next_value else -1
            for value, next_value
            in zip(letter_values, next_letter_values)]

        self.value = sum(
            sign * n * letter_value
            for sign, letter_value, (letter, n)
            in zip(signs, letter_values, letter_counts))

        if self.value > self.MAXIMUM:
            raise ValueError

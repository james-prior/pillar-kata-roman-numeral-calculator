import pytest

from roman import Roman

'''
    4 IV
    9 IX
    14 XIV
    19 XIX
    29 XXIX
    40 XL
    41 XLI
    44 XLIV
    49 XLIX
    74 LXXIV
    89 LXXXIX
    92 XCII
    99 XCIX
    199 CXCIX
    234 CCXXXIV
    345 CCCXLV
    456 CDLVI
    499 CDXCIX
    789 DCCLXXXIX
    890 DCCCXC
    999 CMXCIX
    901 CMI
    1098 MXCVIII
    2109 MMCIX
    3999 MMMCMXCIX
'''

int_string_romans = '''
    1 I
    2 II
    3 III
    5 V
    6 VI
    7 VII
    8 VIII
    10 X
    11 XI
    12 XII
    13 XIII
    15 XV
    16 XVI
    17 XVII
    18 XVIII
    20 XX
    30 XXX
    38 XXXVIII
    50 L
    56 LVI
    65 LXV
    68 LXVIII
    83 LXXXIII
    100 C
    123 CXXIII
    200 CC
    300 CCC
    383 CCCLXXXIII
    500 D
    567 DLXVII
    678 DCLXXVIII
    888 DCCCLXXXVIII
    1000 M
    1883 MDCCCLXXXIII
    2000 MM
    3000 MMM
    3210 MMMCCX
    3883 MMMDCCCLXXXIII
'''.strip().split('\n')
expected_roman_strings = (s.strip().split() for s in int_string_romans)
roman_expected_ints = [
    (roman, int(x))
    for x, roman in expected_roman_strings]
@pytest.mark.parametrize('roman, expected', roman_expected_ints)
def test_known_number_returns_expected(roman, expected):
    assert expected == Roman(roman).get_value()


# bad_romans_expected_errors = (
#     ('', ValueError),
#     ('IL', ValueError),
#     ('XD', ValueError),
#     ('IIII', ValueError),
#     ('IIIII', ValueError),
#     ('VV', ValueError),
#     ('CCCC', ValueError),
#     ('DD', ValueError),
#     ('MMMM', ValueError), # too big value
#     ('ONE', ValueError), # not roman
#     (4000, ValueError), # too big
#     (0, ValueError), # too small
#     (None, TypeError),
#     (float('nan'), TypeError),
#     (1j, TypeError),
# )
# @pytest.mark.parametrize(
#     'bad_roman, expected_exception', bad_romans_expected_errors)
# def test_bad_roman_raises_expected_exception(
#         bad_roman, expected_exception):
#     with pytest.raises(expected_exception):
#         _ = Roman(bad_roman)
# 
# 
# number_expected_roman_strings = (
#     s.strip().split() for s in int_string_romans)
# int_expected_roman_numerals = [
#     (int(x), roman)
#     for x, roman in number_expected_roman_strings]
# @pytest.mark.parametrize(
#     'number, expected_roman_numeral', int_expected_roman_numerals)
# def test_str_returns_expected(number, expected_roman_numeral):
#     assert expected_roman_numeral == str(Roman(number))
# 
# 
# addends_sums_lines = '''
#     I I II
#     I II III
#     II III V
#     III V VIII
#     V VIII XIII
#     VIII XIII XXI
#     XIII XXI XXXIV
#     XXI XXXIV LV
#     XXXIV LV LXXXIX
#     LV LXXXIX CXLIV
#     LXXXIX CXLIV CCXXXIII
#     CXLIV CCXXXIII CCCLXXVII
#     CCXXXIII CCCLXXVII DCX
#     CCCLXXVII DCX CMLXXXVII
#     DCX CMLXXXVII MDXCVII
#     CMLXXXVII MDXCVII MMDLXXXIV
#     MMMCMXCVIII I MMMCMXCIX
# '''.strip().split('\n')
# addends_sums = (
#     s.strip().split() for s in addends_sums_lines)
# @pytest.mark.parametrize('addends_sum', addends_sums)
# def test_adding(addends_sum):
#     addend1, addend2, expected_sum = addends_sum
#     assert expected_sum == str(Roman(addend1) + Roman(addend2))
# 
# 
# bad_adds_expected_errors = (
#     ('MM', 'MM', OverflowError),
#     ('MMMCMXCIX', 'I', OverflowError),
#     ('I', 'MMMCMXCIX', OverflowError),
#     ('MMMCMXCIX', 'MMMCMXCIX', OverflowError),
# )
# @pytest.mark.parametrize(
#     'addend1, addend2, expected_exception', bad_adds_expected_errors)
# def test_bad_add_raises_expected_exception(
#         addend1, addend2, expected_exception):
#     with pytest.raises(expected_exception):
#         Roman(addend1) + Roman(addend2)
# 
# 
# subs_sums_lines = '''
#     II I I
#     III I II
#     V II III
#     VIII III V
#     XIII V VIII
#     XXI VIII XIII
#     XXXIV XIII XXI
#     LV XXI XXXIV
#     LXXXIX XXXIV LV
#     CXLIV LV LXXXIX
#     CCXXXIII LXXXIX CXLIV
#     CCCLXXVII CXLIV CCXXXIII
#     DCX CCXXXIII CCCLXXVII
#     CMLXXXVII CCCLXXVII DCX
#     MDXCVII DCX CMLXXXVII
#     MMDLXXXIV CMLXXXVII MDXCVII
#     MMMCMXCIX MMMCMXCVIII I
# '''.strip().split('\n')
# subs_sums = (
#     s.strip().split() for s in subs_sums_lines)
# @pytest.mark.parametrize('subs_sum', subs_sums)
# def test_subtracting(subs_sum):
#     sub1, sub2, expected_sum = subs_sum
#     assert expected_sum == str(Roman(sub1) - Roman(sub2))
# 
# 
# bad_subs_expected_errors = (
#     ('I', 'I', OverflowError),
#     ('I', 'II', OverflowError),
#     ('M', 'MM', OverflowError),
#     ('MMMCMXCVIII', 'MMMCMXCIX', OverflowError),
#     ('MMMCMXCIX', 'MMMCMXCIX', OverflowError),
# )
# @pytest.mark.parametrize(
#     'sub1, sub2, expected_exception', bad_subs_expected_errors)
# def test_bad_sub_raises_expected_exception(
#         sub1, sub2, expected_exception):
#     with pytest.raises(expected_exception):
#         Roman(sub1) - Roman(sub2)
# 
# 
# roman_expected_repr = (
#     (Roman('I'), "Roman('I')"),
#     (Roman('II'), "Roman('II')"),
#     (Roman('MMMCMXCIX'), "Roman('MMMCMXCIX')"),
# )
# @pytest.mark.parametrize('roman, expected_repr', roman_expected_repr)
# def test_repr(roman, expected_repr):
#     assert expected_repr == repr(roman)

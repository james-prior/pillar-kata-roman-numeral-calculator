import pytest

from roman import Roman

int_string_romans = '''
    1 I
    2 II
    3 III
    4 IV
    5 V
    6 VI
    7 VII
    8 VIII
    9 IX
    10 X
    11 XI
    12 XII
    13 XIII
    14 XIV
    15 XV
    16 XVI
    17 XVII
    18 XVIII
    19 XIX
    20 XX
    29 XXIX
    30 XXX
    38 XXXVIII
    40 XL
    41 XLI
    44 XLIV
    49 XLIX
    50 L
    56 LVI
    65 LXV
    68 LXVIII
    74 LXXIV
    83 LXXXIII
    89 LXXXIX
    92 XCII
    99 XCIX
    100 C
    123 CXXIII
    199 CXCIX
    200 CC
    234 CCXXXIV
    300 CCC
    345 CCCXLV
    383 CCCLXXXIII
    456 CDLVI
    499 CDXCIX
    500 D
    567 DLXVII
    678 DCLXXVIII
    789 DCCLXXXIX
    888 DCCCLXXXVIII
    890 DCCCXC
    901 CMI
    999 CMXCIX
    1000 M
    1098 MXCVIII
    1883 MDCCCLXXXIII
    2000 MM
    2109 MMCIX
    3000 MMM
    3210 MMMCCX
    3883 MMMDCCCLXXXIII
    3999 MMMCMXCIX
'''.strip().split('\n')
expected_roman_strings = (s.strip().split() for s in int_string_romans)
roman_expected_ints = [
    (roman, int(x))
    for x, roman in expected_roman_strings]
@pytest.mark.parametrize('roman, expected', roman_expected_ints)
def test_known_number_returns_expected(roman, expected):
    assert expected == Roman(roman).get_value()


bad_romans_expected_errors = (
    ('', ValueError),

    # log runs
    ('IIII', ValueError),
    ('IIIII', ValueError),
    ('VV', ValueError),
    ('CCCC', ValueError),
    ('DD', ValueError),
    ('MMMM', ValueError), # too big value
    # log runs of subtractive letter
    ('IIV', ValueError),
    ('IIX', ValueError),
    ('XXL', ValueError),
    ('XXC', ValueError),
    ('CCM', ValueError),
    # invalid subtractive combinations
    ('IL', ValueError),
    ('IC', ValueError),
    ('ID', ValueError),
    ('IM', ValueError),
    ('VX', ValueError),
    ('VL', ValueError),
    ('XD', ValueError),
    ('XM', ValueError),

    ('ONE', ValueError), # not roman
    # (4000, ValueError), # too big
    (-1, ValueError), # too small
    (0, ValueError), # too small
    # (None, TypeError),
    # (float('nan'), TypeError),
    # (1j, TypeError),
)
@pytest.mark.parametrize(
    'bad_roman, expected_exception', bad_romans_expected_errors)
def test_bad_roman_raises_expected_exception(
        bad_roman, expected_exception):
    with pytest.raises(expected_exception):
        Roman(bad_roman)


number_expected_roman_strings = (
    s.strip().split() for s in int_string_romans)
ints = [
    int(x)
    for x, roman in number_expected_roman_strings]
@pytest.mark.parametrize(
    'number', ints)
def test_str_returns_expected(number):
    assert number == Roman(number).get_value()


number_expected_roman_strings = (
    s.strip().split() for s in int_string_romans)
int_expected_roman_numerals = [
    (int(x), roman)
    for x, roman in number_expected_roman_strings]
@pytest.mark.parametrize(
    'number, expected_roman_numeral', int_expected_roman_numerals)
def test_str_returns_expected(number, expected_roman_numeral):
    assert expected_roman_numeral == str(Roman(number))


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

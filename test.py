#!/usr/bin/env python3
import random

from pangolin import Executable, Test
from itertools import permutations

Armstrong = Executable('./armstrong')


def is_armstrong(n):
    return sum([int(i)**len(str(n)) for i in str(n)]) == n


def get_armstrong_number():
    digits = random.randint(1, 6)
    return sum([random.randint(0, 9) ** digits for digit in range(digits)])


def get_not_armstrong_number():
    n = random.randint(10, 2**31 - 1)
    if is_armstrong(n):
        return get_not_armstrong_number()
    return n


class TestArmstrong(Test):

    def test_arguments(self):
        "Test des codes d'erreurs"

        self.test("Éxecution sans arguments", Armstrong().exit_status == 2)

    def test_basic(self):
        "Test des valeurs de base"

        for args, exit_status in {33: True, 153: False, 154: True}.items():
            out = Armstrong(args).exit_status
            self.test(f"Valeur {args}",  out == exit_status,
                      f"Bad exit status '{out}' for input '{args}', expected '{exit_status}'")

        for i in range(10):
            assert(Armstrong(i).exit_status == 0)

    def test_random_not_armstrong(self):
        "Test aléatoire pour des nombres non narcissiques"

        for n in [get_not_armstrong_number() for i in range(10)]:
            out = Armstrong(n).exit_status
            self.test(f"Valeur {n} n'est pas un nombre d'Armstrong", out == int(not is_armstrong(n)),
                      f"Bad exit status '{out}' for input '{n}', expected '{is_armstrong(n)}'")

    def test_random_armstrong(self):
        "Test aléatoire pour des nombres narcissiques"

        for n in [get_armstrong_number() for i in range(10)]:
            out = Armstrong(n).exit_status
            self.test(f"Valeur {n} est un nombre d'Armstrong", out == int(not is_armstrong(n)),
                      f"Bad exit status '{out}' for input '{n}', expected '{is_armstrong(n)}'")

    def test_version(self):
        "Test de l'option --version"

        num = random.randint(10, 100000)

        for args in list(permutations(['--version', '--verbose', str(num)], 3)):
            self.test(f"armstrong {' '.join(args)}", Armstrong(*args).stdout.grep('(?i)version'))

        self.test("Présence d'email", Armstrong('--version').stdout.grep('<.*?@.*?>'))

    def test_verbose(self):
        "Test de l'option verbose"

        n = 564
        self.test(f"Valeur {n} sur stdout avec --verbose",  len(
            Armstrong('--verbose', n).stdout.grep(r'\b%d\b' % n)))

        self.test(f"Valeur {n} sur stdout avec -v",  len(
            Armstrong('-v', n).stdout.grep(r'\b%d\b' % n)))

        for args, exit_status in {33: True, 153: False, 154: True}.items():
            self.test(f"Valeur {args}", len(
                Armstrong('--verbose', args).stdout.grep('\bpas\b|\bis\b')) == 0)

    def test_stdin(self):
        "Test avec stdin"

        self.test("cat 153 | armstrong", Armstrong(stdin=b'153').exit_status == 0)
        self.test("cat 154 | armstrong", Armstrong(stdin=b'153').exit_status == 1)
        self.test("cat 153 | armstrong", Armstrong('--verbose', stdin=b'153').exit_status == 0)
TestArmstrong()

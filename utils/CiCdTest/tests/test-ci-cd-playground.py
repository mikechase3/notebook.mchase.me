import unittest
from unittest.mock import patch
# from CiCdTest.ci-cd-playground import print_message
from ci-ci_cd_playground.

class TestCiCdPlayground(unittest.TestCase):
    @patch('builtins.print')
    def test_print_message(self, mock_print):
        print_message()
        mock_print.assert_called_once_with("Congrats, Mike Chase! Your CI/CD Works!")

if __name__ == '__main__':
    unittest.main()
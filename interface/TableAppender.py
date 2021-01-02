"""This class handles the whole 'list/string' to markdown functionality. -Mike Chase"""

import os.path
from pathlib import Path
from typing import List


class TableAppender:
	"""Appends strings and lists to a table inside a markdown file"""
	FILE_HEADER = ["Quote", "Source", "Comment"]  # Final (mostly), sanitized in __init__ in case you screw up 😂
	FILE_PATH: str = ""  # Final (mostly), assigned in the initializer only.
	appender = None

	def __init__(self, file_name_and_path: str = "") -> None:
		""" Set variables & appender.

		Parameters
		----------
		file_name_and_path : str, optional.
			Will default to INBOX.md in the parent directory.

		Returns
		---------
		None
			Just an Initializer for the class.
		"""
		# Determine file path to write to & save it to File_Path
		if len(file_name_and_path) < 2:  # No location specified? Append it to my Github...
			current_path = Path("main.py").parent.absolute()
			parent_path = current_path.parent
			file_name_and_path = str(parent_path) + "/inbox.md"  # Located the file we're writing to.
			self.FILE_PATH = file_name_and_path
		else:  # Use location passed in during initialization.
			self.FILE_PATH = file_name_and_path  # Initialize the global variable.

		# Examine the file.
		self.FILE_HEADER = [h.replace('|', '') for h in self.FILE_HEADER]
		self.appender = open(self.FILE_PATH, 'a')

		# Write the header if it's a new-ish file. (Minus description)
		if os.stat(self.FILE_PATH).st_size < 100:  # 88chars is the current desciption and '# Inbox` header.
			self.write_header(self.appender, self.FILE_HEADER)

	def sanitize_string(self, input_str: str) -> str:
		""" Sanitizes a string for markdown table format.

		Parameters
		-------
		input_str : str
			Any string.


		Returns
		-------
		str

		"""
		# Uncomment the following lines if it's a CSV instead of a markdown table.
		# s = s.replace(',', '')  # CSV: A backup plan. This will just remove all the commas.
		# s = s.replace('\"', '')  # CSV: Remove any double quotes which might screw up the CSV.
		# s = s.replace('\'', '')  # CSV: Remove the single quotes which might screw up the CSV.
		# s = "\"" + s + "\""  # CSV: Now put these in quotes.

		# For md table
		s = input_str.replace('|', '')  # Remove all pipelines which will screw up the markdown table.
		return s

	def insert_vertical_bar_spacer(self, input_str: str) -> str:
		""" Takes a string and adds a vertical line & corresponding spaces."""
		input_str = "| " + input_str + " |"
		return input_str

	def write_header(self, appender, file_header: List[str]) -> None:
		""" Performed on init. Adds header.
		Parameters
		----------
		appender : open()
			Weird appender type
		file_header : List[str]
			Each element is a header.


		Returns
		-------
		None


		"""
		# writer = csv.writer(appender, delimiter="|", lineterminator='\n')  # Old, for CSVs only.
		header_string = "|"
		for head_title in file_header:
			header_string = " " + header_string + head_title + "|"  # First two lines of the table.
		header_string = header_string + "\n| :--- | :--- | :--- |"  # First two lines of the table.
		appender.write("\n" + header_string)

	def str_append_to_file(self, text: str) -> None:  # Depreciated
		"""Appends a string to a text file after sanitizing"""
		self.appender.write("\n" + text)
		self.appender.close()

	def append_list(self, one_row_as_list: List[str]) -> None:
		""" Takes list and appends new row.

		Parameters
		----------
		one_row_as_list : List[str]: List of things to add to one row. Each element is a column.

		Returns
		----------
		None

		"""
		header_string = "|"
		for t in one_row_as_list:
			t = self.sanitize_string(t)
			header_string = " " + header_string + t + "|"
		self.appender.write("\n" + header_string)

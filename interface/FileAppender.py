import csv
import os.path
from typing import *


class FileAppender:
	FILE_HEADER = ["Quote", "Source", "Comment"]
	appender = None
	file_path = ""

	def __init__(self, file_name_and_path: str = (str(os.path) + "output.csv")) -> None:
		"""Initializes the append function.
		@:param self
		@:param file_name_and_path: The path & filename to save results.
		"""
		self.appender = open(file_name_and_path, 'a')
		self.file_path = file_name_and_path
		if os.stat(file_name_and_path).st_size == 0:  # Write the header if it's a new file.
			self.write_header()  # BUG: Will not write if file is 100% empty.
			# print("This looks like a new file. Added a header.")

	def write_header(self):
		# Will wrongly append header if it already exists in a file.
		# I fixed this temporarily in L18 w/ the if statement, but corner case of file exists w/o headers is bad.
		file_exists = self.file_path
		writer = csv.writer(self.appender, delimiter=",", lineterminator='\n')
		if not file_exists:
			writer.writeheader()  # File doesn't exist yet, write a header.
		writer.writerow(self.FILE_HEADER)

	def append_to_file(self, text: str) -> None:
		"""Appends a string to a text file"""
		self.appender.write("\n" + text)
		self.appender.close()

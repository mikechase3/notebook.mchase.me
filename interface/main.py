import os
import sys
from enum import Enum

from FileAppender import FileAppender


class Location(Enum):
	INBOX = "/Users/mikechase3/Dropbox/Active Documents/Inbox/ForTheWall/QUOTES.csv"  # Mike Chase's default location.
	CURRENTPATH = str(os.path) + "output.csv"


def sanitize(s: str) -> str:
	"""Sanitizes a string by appending quotes around it. """
	# s = s.replace(',', '')  # A backup plan. This will just remove all the commas.
	s = s.replace('\"', '')  # Remove any double quotes which will screw up the CSV.
	s = s.replace('\'', '')  # Remove the single quotes which will screw up the CSV.
	s = "\"" + s + "\""  # Now put these in quotes.
	return s


def addQuote(quote: str, source: str = "Not Specified", comment: str = '',
             location: str = (str(Location.INBOX.value))) -> None:
	""" Adds a quote to the CSV: quote, src, comment, str.
	:param source: The source or where you heard it.
	:type source: str
	:rtype: None
	:param quote: Quote to be added to the file
	:type quote: str
	:param comment: Comment about the quote.
	:type comment: str
	:param location: the location to save the file to. Is the terminal path to begin with.
	:type location: str
	"""
	appender = FileAppender(location)
	quote = sanitize(quote)
	comment = sanitize(comment)
	source = sanitize(source)
	appender.append_to_file(quote + "," + source + "," + comment)


if __name__ == '__main__':
	""" Stores a quote and comment in a file
	@:arg: Self (you can ignore this)
	@:arg[1]: The quote
	@:arg[2]: The comment
	@:arg[3]: The file location
	"""
	# print("NumArgs: ", len(sys.argv), end="; ")  # Debugging
	# print("Argument List: ", str(sys.argv))

	if len(sys.argv) == 1:
		keepRunning = True
		location = ""
		while keepRunning:
			quote = input("Enter the quote you'd like to save: ")
			source = input("Who or what is the source: ")
			comment = input("Enter a comment: ")
			try:  # User validation
				locationOption = input(
					"Do you want to save this to mike's (i)nbox, the (c)urrent directory, or somewhere (e)lse?")
				if locationOption == "i":
					location = Location.INBOX.value
				elif locationOption == "c":
					location = Location.CURRENTPATH.value
				elif locationOption == "e":
					location = input("Type the in the location. This is relative to the script's location but a fixed "
					                 "location is also acceptable.")
				else:
					raise Exception("You selected an invalid option. Type 'i', 'c', or 'e' and try again.")
			except:
				continue

			# Ask the user if everything looks right.
			i = input(
				"\n===========================\n" + "Quote: " + quote + "\nSource: " + source + "\nComment: " + comment
				+ "\nLocation: '" + str(location) + "' ?  \n===========================\nDoes this look right? (y/n): ")
			if i == "y" or "Y" or "yes":
				addQuote(quote, source, comment, location)
				print("Success. Added to: ", location)
			else:
				print("Ok, I didn't add it.")
			print("----------------------")

			i = input("Would you like to add another quote? (y/n)? ")
			if i == "y":
				continue
			else:
				keepRunning = False
				print("Ended")

	# TODO: Keep Running?
	elif len(sys.argv) == 2:  # Quote w/o comment
		addQuote(sys.argv[1])
		print("Appended to " + Location.INBOX.value, "with no comment")
	elif len(sys.argv) == 3:  # Quote & Source
		addQuote(sys.argv[1], sys.argv[2])
		print("Appended to: " + Location.INBOX.value)
	elif len(sys.argv) == 4:  # Quote, Source, and Comment
		# Ask the user if everything looks right.
		i = input(
			"\n===========================\n" + "Quote: " + sys.argv[1] + "\nSource: " + sys.argv[2]
			+ "\nComment: '" + sys.argv[3] + "' ?  \n Does this look right?: (y/n): ")
		print("\n===========================\n")
		if i == "y" or "Y" or "yes":
			addQuote(sys.argv[1], sys.argv[2], sys.argv[3])
			print("\nSuccess. Added to: ", Location.INBOX.value)
		else:
			print("Ok, I didn't add it.")
		print("Added!")
	elif len(sys.argv) == 5:  # Quote, source, comment, and location
		addQuote(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
		print("\nSuccess. Added to: ", sys.argv[4])

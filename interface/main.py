import os
import sys
from enum import Enum
# from interface.TableAppender import TableAppender
import TableAppender

class Location(Enum):
	INBOX = "/Users/mikechase3/Dropbox/Active Documents/Inbox/ForTheWall/QUOTES.csv"  # Mike Chase's default location.
	CURRENT_PATH = str(os.path) + "output.csv"


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
					"Do you want to save this to (g)ithub, mike's (i)nbox, the (c)urrent directory, or somewhere (e)lse? ")
				if locationOption == "i":
					location = Location.INBOX.value
				elif locationOption == "g":
					location = ""  # Will be converted in FileAppender.py
				elif locationOption == "c":
					location = Location.CURRENT_PATH.value
				elif locationOption == "e":
					location = input("Type the absolute or relative location: ")
				else:
					raise ValueError("Invalid option selected. Program terminated.")
			except ValueError:
				exit()

			# Ask the user if everything looks right.
			i = input(
				"\n===========================\n" + "Quote: " + quote + "\nSource: " + source + "\nComment: " + comment
				+ "\nLocation: '" + str(location) + "' ?  \n===========================\nDoes this look right? (y/n): ")
			if i == "y" or "Y" or "yes":
				appender = interface.TableAppender(location)
				to_append = [quote, source, comment]
				appender.append_list(to_append)
				print("Success. Added to: ", location)
			else:
				print("Ok, Mike Chase didn't add it.")
			print("----------------------")

			i = input("Would you like to add another quote? (y/n)? ")
			if i == "y":
				continue
			else:
				keepRunning = False  # will return exit 0.
				print("Ended\n")

	# TODO: Keep Running?
	elif len(sys.argv) == 2:  # Quote only.
		l = []
		l[0] = sys.argv[1]  # Quote
		l[1] = "No Source Provided"  # Source
		l[2] = "No Comment Provided"
		location = ""  # Location

		# Add to markdown file.
		appender = interface.TableAppender("")
		appender.append_list(l)
		print("Appended your quote (w/o source or comment) to the table on Github. Make sure to commit & push!")

	elif len(sys.argv) == 3:  # Quote & Source & Comment
		l = []
		l[0] = sys.argv[1]  # Quote
		l[1] = sys.argv[2]  # Source
		l[2] = "No Comment Provided"
		location = ""  # Location

		# Add to markdown file.
		appender = interface.TableAppender("")
		appender.append_list(l)
		print("Appended your quote & source to the table on Github. Make sure to commit & push!")
	elif len(sys.argv) == 4:  # Quote, Source, and Comment
		l = []
		l[0] = sys.argv[1]  # Quote
		l[1] = sys.argv[2]  # Source
		l[2] = sys.argv[3]  # Comment
		location = ""  # Location

		# Add to markdown file.
		appender = interface.TableAppender(location)
		appender.append_list(l)
		print("Appended your quote & source & comment to the table on Github. Make sure to commit & push!")
	elif len(sys.argv) == 5:  # Quote, source, comment, and location
		l = []
		l[0] = sys.argv[1]  # Quote
		l[1] = sys.argv[2]  # Source
		l[2] = sys.argv[3]  # Comment
		location = sys.argv[4]  # Location

		# Add to markdown file.
		appender = interface.TableAppender(location)
		appender.append_list(l)
		print("Appended your quote & source & comment to the table at", location)

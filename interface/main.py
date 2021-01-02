import os
import sys
from enum import Enum
from pathlib import Path

from interface.TableAppender import TableAppender
from interface.UserInterface import UI

class Location(Enum):
	INBOX = "/Users/mikechase3/Dropbox/Active Documents/Inbox/ForTheWall/QUOTES.csv"  # Mike Chase's default location.
	CURRENT_PATH = str(os.path) + "output.csv"
	GITHUB_INBOX_PATH = "/Users/mikechase3/Dropbox/Active Documents/16th Grade/Personal/Git Repositories/Notebook/notebook-mchase-me/inbox.md"

def launchUI():
	"""Launch the UI"""
	ui = UI()



def text_interface():  # Takes system arguments
	"""
	Parameters
	-------
	System Args
		0: application
		1: Quote, opt
		2: Source, opt
		3: Comment, opt
		4: Save location, opt

	Returns
	-------
	None

	"""
	if len(sys.argv) == 1:
		keep_running = True
		location = ""
		while keep_running:
			quote = input("Enter the quote you'd like to save: ")
			source = input("Who or what is the source: ")
			comment = input("Enter a comment: ")
			try:  # User validation
				location_option = input(
					"Do you want to save this to (g)ithub, mike's (i)nbox, the (c)urrent directory, or somewhere (e)lse? ")
				if location_option == "i":
					location = Location.INBOX.value
				elif location_option == "g":
					location = ""  # Will be converted in FileAppender.py
				elif location_option == "c":
					location = Location.CURRENT_PATH.value
				elif location_option == "e":
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
				appender = TableAppender(location)
				to_append = [quote, source, comment]
				appender.append_list(to_append)
				print("Success. Added.")
			else:
				print("Ok, Mike Chase didn't add it.")
			print("----------------------")

			i = input("Would you like to add another quote? (y/n)? ")
			if i == "y":
				continue
			else:
				keep_running = False  # will return exit 0.
				print("Ended\n")

	# TODO: Keep Running?
	elif len(sys.argv) == 2:  # Quote only.
		l = [sys.argv[1], "No Source Provided", "No Comment Provided"]
		location = Location.GITHUB_INBOX_PATH.value  # Location. BUG: Should be relative.

		# Add to markdown file.
		appender = TableAppender(location)
		appender.append_list(l)
		print("Appended your quote (w/o source or comment) to the table on Github. Make sure to commit & push!")

	elif len(sys.argv) == 3:  # Quote & Source & Comment
		l = [sys.argv[1], sys.argv[2], "No Comment Provided"]
		location = Location.GITHUB_INBOX_PATH.value  # Location. BUG: Should be relative.

		# Add to markdown file.
		appender = TableAppender(location)
		appender.append_list(l)
		print("Appended your quote & source to the table on Github. Make sure to commit & push!")
	elif len(sys.argv) == 4:  # Quote, Source, and Comment
		l = [sys.argv[1], sys.argv[2], sys.argv[3]]
		location = Location.GITHUB_INBOX_PATH.value  # Location. BUG: Should be relative.

		# Add to markdown file.
		appender = TableAppender(location)
		appender.append_list(l)
		print("Success")
	# git_mgr = GitManager("this does noting ignore me")
	# git_mgr.update_repo(git_mgr)
	# print("Maybe it pushed?")

	elif len(sys.argv) == 5:  # Quote, source, comment, and location
		l = [sys.argv[1], sys.argv[2], sys.argv[3]]

		location = sys.argv[4]  # Location

		# Add to markdown file.
		appender = TableAppender(location)
		appender.append_list(l)
		print("Saved")
	debug_github_path()


def debug_github_path():
	""" Debugging for github file relative paths only."""
	# print("DEBUGGING: APPLIES TO GITHUB FILE ONLY:")
	# current_path = Path("main.py").parent.absolute()
	# parent_path = current_path.parent
	# file_name_and_path = str(parent_path) + "/inbox.md"  # Located the file we're writing to.
	file = open(Location.GITHUB_INBOX_PATH.value, "r")
	print(file.read())


if __name__ == '__main__':
	""" Stores a quote and comment in a file
	@:arg: Self (you can ignore this)
	@:arg[1]: The quote
	@:arg[2]: The comment
	@:arg[3]: The file location
	"""
	print("DEBUG_NumArgs: ", len(sys.argv), end="; ")  # Debugging
	print("DEBUG_Argument List: ", str(sys.argv))

	text_interface()  # TODO: UNDELETE
	# launchUI()
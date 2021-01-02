"""This class exists to push my work onto Github when it's finished. Currently doesn't work """

from github import Github, InputGitAuthor
from interface.TableAppender import TableAppender


class GitManager:
	"""Pushes to Github"""
	SECRET_TOKEN = "fb179e83eb0901f319371d2d1f7f9249ffae00dd"

	def __init__(self, test_str: str) -> None:
		a = "this does nothing ignore me."


	@staticmethod
	def update_repo(self, file_path: str = "inbox.md") -> None:  # Fix default later.
		""" Updates inbox.md

		Parameters
		----------
		file_path : str
			The file's path relative to the repository's root.

		Returns
		-------
		None

		"""

		# Get the contents of the file. Not very relavant yet.
		g = Github(self.SECRET_TOKEN)
		repo = g.get_repo("mikechase3/notebook-mchase-me")

		file = repo.get_contents(file_path, ref="master")  # Get file from branch
		data = file.decoded_content.decode("utf-8")  # Get raw string data. Not used.
		data += "\npytest==5.3.2"  # Modify/Create file. Not used.

		# Access modified data. Store it to be re-pushed.
		modified_data = TableAppender.FILE_PATH

		def push(path: str, message: str, content: str, branch: str, update: bool = True) -> None:
			""" Create new branch originating from commit & push.

			Parameters
			----------
			path : str
				I'm 80% sure it's a string. Hopefully not a weird path object.
			message : str
				Commit Message
			content : str
				Content we're comitting
			branch : str
				The branch we're deploying to.
			update : bool
				True -> updating. False -> new file.
			"""
			author = InputGitAuthor(
				"Michael Chase",
				"protectmikechase@gmail.com"
			)
			source = repo.get_branch("master")
			repo.create_git_ref(ref=f"refs/heads/{branch}", sha=source.commit.sha)  # Create new branch from master
			if update:  # If file already exists, update it
				contents = repo.get_contents(path, ref=branch)  # Retrieve old file to get its SHA and path
				repo.update_file(contents.path, message, content, contents.sha, branch=branch,
				                 author=author)  # Add, commit and push branch
			else:  # If file doesn't exist, create it
				repo.create_file(path, message, content, branch=branch, author=author)  # Add, commit and push branch

		push(file_path, "Add pytest to dependencies.", modified_data, "update-dependencies", update=True)

# Git Flash Cards

## Inspiration

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

I'm considering making a flashcard deck for the team. The bolded headings would be the "term" and the body is on the back.

## Initialization

### How do you check if git is installed?

* You can verify your Git installation by asking for the version using: `git version`
* Furthermore, we can check if a folder is initialized?

### How do you initialize a folder?

* Use `git init` to initialize a new repository for a project.&#x20;

```bash
$ git init
Initialized empty Git repository in /root/commit-exercise/.git/
```

When you initialize git, it creates a `.git` folder in the folder you've initialized that creates specific files needed for revision history:

<figure><img src="../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

## Committing

### How do you Make a Commit on Main?

1. Add the file to Git's index using `git add README.md`
2. Run the `git commit -m "message"` command.&#x20;

### What is an Index?

It's where you stage files until you're ready to commit.

### How do you unstage a file?

* Use `git rm --cached <file>...` to unstage but keep the files.
* Use `git rm -f <file>` to unstage and delete the file troo.

## Branches

* Branches represent a series of commits.
* Typically, you start with just the main/master branch.&#x20;
* Use `git branch` to get a list of all branches in your repository.

### How do you create a new branch?

* Pass the name of the branch as an argument to the branch command such as `git branch second-branch`.&#x20;
* Use the `switch` command to switch between branches. For example: `git switch master`.
* Note - you won't switch to the branch just by creating it unless you use the `git switch`` `**`-c`**` ``newBranchName`.&#x20;
* When you create a new branch, it's based off work done by the last branch.&#x20;

###


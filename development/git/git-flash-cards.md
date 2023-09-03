---
description: Easy, Beginner Level Cards
---

# Git Flash Cards

## Inspiration

<figure><img src="../../.gitbook/assets/image (2) (1).png" alt=""><figcaption></figcaption></figure>

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

<figure><img src="../../.gitbook/assets/image (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

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

### How do you revert your changes?

```python
if modified but not staged
    git restore <file>
    
if modified and staged:
    git restore --staged <file>  # reverts 
```

### How do you merge branches together?

1. Switch to your master branch or the branch where you expect changes to be merged into.
2. Use the `merge` keyword: `git merge -m "merge the feature branch into main" feat-branch`.&#x20;

### What if there's a conflict?

Here's the example that I worked with.

1. First, I went into main & started a README
2. Then, I went into the feature branch & added a new line to README
3. Following that, I switched back to the main branch and edited the README.
4. When using the merge command, I have a conflicted file. Git auto-adds the differences in plain text.
5. Go into the file & remove the 'head' markers manually.
6. Stage & commit the conflicted file.&#x20;

## Merge Conflicts

### Log

* Git has a log containing commit history.
* View the log with `git log --graph --oneline --all`

{% embed url="https://git-scm.com/docs/git-log" %}

### Diff the Working Dir and Index

Let's say we've made edits to a file previously committed. We can tell what changed using the `diff` command before we staged it, but how we use that command depends on whether or not we've already staged the file or not:

* **If we staged the file**: use `git diff --cached <file>` to compare it to the staged file (or most recent commit if there are no staged changes).
* If we haven't staged the file, use `git diff <file>` to compare changes to the last staged change in the previous commit.&#x20;

### Comparing Commit IDs

To get the commit IDs in linux, we can use these commands:

* `IRST_COMMIT_ID=$(git rev-parse --short HEAD~1)`
* `SECOND_COMMIT_ID=$(git rev-parse --short HEAD)`

Now we can use the `diff` command `git diff $FIRST_COMMIT_ID $SECOND_COMMIT_ID`. (Note, we can type in the IDs manually)




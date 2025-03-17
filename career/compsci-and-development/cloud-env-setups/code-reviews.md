# Code Reviews

{% embed url="https://www.youtube.com/watch?v=TlXy_i27N3w" %}
Source of content. Notes below.
{% endembed %}

## Why Review Other's Code?

1. Add comments to specific lines of code
2. Ask questions about lines of code.
3. Make suggestions of how to make it better.
4. Helps **maintain best practices** and consistency across a code base.
5. **Educate others** on the code going into the code base.
6. **Reduces the bus-factor** of one team member having too much knowledge (such that if he were to be hit by a buss other people could figure it out).

## Where do Reviews Happen?

1. Stash, Git, or Bitbucket.
2. Oftentimes, this is going to happen in the context of a **pull request.**

## Successful Steps

1. Figure out what the code is doing.
   1. What is the purpose?
   2. Why does this code exist?
   3. Do you have the right background information?
   4. Do you understand how this code fits into the entire project?
2. Frame your mind.
   1. How experienced are you with the codebase/language
   2. Are you going to be using this code in the future?
   3. Have you written code similar to this?
   4. What is the experience of the author?
   5. What is your relationship with the author?
3. Test the code.
   1. Test the functionality of the code.
   2. Checkout the branch where the changes were made.
   3. Does the code generate warnings or errors?
   4. Does the code take longer to build or run than normal?
   5. Do the changes require any additional setup?
4. Inspect the code.
   1. Are current naming conventions followed?
   2. Is the code DRY (do not repeat yourself)
   3. Are the new files and folders named appropriately?
   4. Does the code have error handling?
5. Compile your review.
   1. Write up a formal document and submit to authors.
   2. In Github, you can add comments and questions in a comment thread.
   3. Create a new branch with suggested changes.
   4. Beware of biteshedding (nitpicky things that don't matter and are opinion base).
   5. Be respectful, specific, and descriptive.
   6. Offer follow ups.


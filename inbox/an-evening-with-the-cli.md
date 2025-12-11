# An Evening with the CLI

## Gitlab CLI

[Cheat Sheet](https://jinaldesai.com/the-ultimate-cli-cheat-sheets-collection/#GitLab_glab_CLI_Cheat-Sheet) (7.3)

<figure><img src="../.gitbook/assets/CleanShot 2025-12-10 at 18.58.12.png" alt=""><figcaption></figcaption></figure>

### Authenticating

* glab auth login
  * Paste an auth token
  * Or use a web login to get a token quickly.

### Cloning a Repo Quickly

* glab repo clone gitlab.com/\<GROUP>/\<PROJECT>&#x20;

### Create a new issue

In your project repo, do filter:&#x20;

* &#x20;`glab issue list --assignee mikechase3 --label bug --state open`
* `glab issue create --title "Say Hello World" -- body "Hello CLI"`        &#x20;

## W3M



* Browse the web through the CLI
* Why? Because I hate JS bullcrappery.
* Style points.
* Warning - it's not as efficient (yet).



{% @github-files/github-code-block url="https://github.com/janosgyerik/cheatsheets/blob/master/W3m-cheat-sheet.mediawiki" %}

# glab cli docs

## Official Glab CLI Docs

{% embed url="https://docs.gitlab.com/editor_extensions/gitlab_cli/" %}

## Getting Help

So use `glab --help` to see the available commands & find subcommands using glab \<subtopic> --help and so on.

## Core Commands

* auth login
* issue: list
* label: idk
* repo: clone

## Ubuntu Installation

1. Download the file w/ `curl -L -o <filename>.deb <URL>`&#x20;
   1. -L follows redirects
   2. -o tells it to save and output a filename instead of stdout probably.
2. Use `dpkg` to install: `sudo dpkg -i <filename>.deb`
3. Fix any missing dependencies w/ `sudo apt install -f`

{% hint style="info" %}
Don't installl from snap
{% endhint %}

Then set vim as the default editor with:

```
sudo update-alternatives --config editor
```

Check with  `glab config get editor --global`

If that doesn't work, use&#x20;

`glab config set editor vim --global` to set it as Gitlab's default with that tool.






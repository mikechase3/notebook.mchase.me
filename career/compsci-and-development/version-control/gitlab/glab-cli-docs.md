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

### #1 Download [Release](https://gitlab.com/gitlab-org/cli/-/releases)

Go to the releases & get the proper one for your operating system.&#x20;

Download the file w/ `curl -L -o <filename>.deb <URL>`

1. -L follows redirects
2. -o tells it to save and output a filename instead of stdout probably.
3. Use `dpkg` to install: `sudo dpkg -i <filename>.deb`
4. Fix any missing dependencies w/ `sudo apt install -f`

```bash
curl -L -o glab.deb https://glabCliLongPath.deb 
```

Here's an example to copy/paste in a pinch.

```bash
curl -o glab_1.77.0_linux_amd64.deb https://gitlab.com/gitlab-org/cli/-/releases/v1.77.0/downloads/glab_1.77.0_linux_amd64.deb
```

{% hint style="info" %}
Don't install from snap. Sandboxing causes problems with vim.
{% endhint %}

Then set vim as the default editor systemwide with:

```
sudo update-alternatives --config editor
```

And/Or within `glab` using:

```bash
glab config get editor --global
glab config set editor vim --global
```


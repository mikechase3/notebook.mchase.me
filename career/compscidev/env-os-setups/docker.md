# Docker

## Getting Started

1. Download/install docker.
2.  Run the tutorial \`

    ```
    docker run -d -p 80:80 docker/getting-started
    ```



## Docker on CloudShell

First, make your cloud shell instance. If you have an RSA private key like me, make sure you use Putty KeyGen to make a `.ppk` file first.

<figure><img src="../../../.gitbook/assets/image (751).png" alt=""><figcaption></figcaption></figure>

Then find your external IP

<figure><img src="../../../.gitbook/assets/image (752).png" alt=""><figcaption></figcaption></figure>

Then get frustrated. Enable password authentication and ssh in. Then get your SSH keys fixed by adding it to `/etc/ssh/sshd_config` and run `sudo systemctl restart sshd` and `sudo service ssh restart` before going back into `/etc/ssh/sshd_config` to disable password authentication by setting `PasswordAuthentication no` and scratch your head asking why password authentication works before giving up and saying "I have the VM set to destroy itself in 55hrs anyways I guess that's secure enough with a strong password." Which isn't good practice, but for a dev machine with little else on it, it'll work unless they break in and steal my gitlab credentials that aren't that widely scoped anyways. Boo.




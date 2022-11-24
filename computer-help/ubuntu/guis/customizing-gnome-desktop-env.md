# Customizing Gnome Desktop Env

## Definitions

* Gnome is the entire desktop environment
* Nautilus is a file manager that does FTP, SFTP, etc. It is the default gnome file manager shipped with the Gnome Desktop Environment.
* [XDG](https://superuser.com/questions/1559357/what-does-xdg-stand-for) stands for "cross desktop group" and helps with compatibility between systems.

## Changing "Places" Menu

{% embed url="https://askubuntu.com/questions/44449/ubuntu-desktop-suddenly-points-to-home-folder" %}

Once you have recreated the Documents folder, make sure your `~/.config/user-dirs.dirs` contains something like this:

```
XDG_DESKTOP_DIR="$HOME/Desktop"
XDG_DOWNLOAD_DIR="$HOME/Downloads"
XDG_DOCUMENTS_DIR="$HOME/Documents"
XDG_MUSIC_DIR="$HOME/Music"
XDG_PICTURES_DIR="$HOME/Pictures"
XDG_VIDEOS_DIR="$HOME/Videos"
```

You can edit it as needed using any text editor, for example

```
nano ~/.config/user-dirs.dirs
```

Then run the command `xdg-user-dirs-gtk-update`. If that doesn't fix it, restart Nautilus by typing `nautilus -q` to restart.





## Bookmarks

\~/.config/gtk-3.0/bookmarks

```
file:///home/%yourusername%/Documents
file:///home/%yourusername%/Music
file:///home/%yourusername%/Pictures
file:///home/%yourusername%/Videos
file:///home/%yourusername%/Downloads
```


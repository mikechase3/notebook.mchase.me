# Greenshot Config

## Greenshot Download

{% embed url="https://getgreenshot.org/" %}

## Hotkey Configuration

The default is to use the printscrn button on a keyboard, but this hardly works because Windows annoyingly is pushing their new snipping tool which consumes the input of that button even if you disable it.&#x20;

### Mike Chase's Default Workaround

Therefore, I recommend changing the **capture region hotkey to CTRL+HOME** which I'm sure will cause conflicts later but it works for now.

<figure><img src="../../../../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>

### Disable the New Snipping Tool

I spent \~15m and couldn't get the default `printscsrn`button to work, so I'd just stick to the above method; however, for the sake of completion here's how you disable the `printscrn`default functionality. This allowed me to take screenshots on my primary monitor only, but not secondary ones, so that's rather useless.&#x20;



<figure><img src="../../../../../.gitbook/assets/image (3).png" alt=""><figcaption></figcaption></figure>

### Disable via Registry

I think disabling the snipping tool reverts you to the old-school version where it'll just print the screen. It still consumes input. You can disable the older functionality in the registry editor:

<figure><img src="../../../../../.gitbook/assets/image (5).png" alt=""><figcaption></figcaption></figure>




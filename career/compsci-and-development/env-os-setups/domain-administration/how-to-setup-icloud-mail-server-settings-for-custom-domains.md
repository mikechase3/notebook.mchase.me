# How To Setup iCloud Mail Server Settings for Custom Domains

## Problem

1. I wanted to use Thunderbird & Google Mail to send/receive emails through my custom domain.
2. Their instructions suck.

### Apple's Instructions

When you search for it, you'll likely come across this article: [https://support.apple.com/en-us/102525](https://support.apple.com/en-us/102525) which lists some example DNS settings that **do not apply for custom domains!!**

<figure><img src="../../../../.gitbook/assets/CleanShot 2025-10-18 at 07.48.28@2x.png" alt=""><figcaption></figcaption></figure>

## The Solution

1. You'll need to use your @icloud.com email address for authentication. Since this is replaced with your custom domains & you can no longer receive/check, you have to go to
2. Use an [app-specific password](https://support.apple.com/en-us/102654) generated from your "Manage your Apple Account" page (which isn't shown in iCloud by the way)

<figure><img src="../../../../.gitbook/assets/CleanShot 2025-10-18 at 07.51.14@2x.png" alt=""><figcaption></figcaption></figure>

## Configuring Gmail

Setup your @custom-domain.com, but in the authentication settings, use your @icloud.com email address.

<figure><img src="../../../../.gitbook/assets/image (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

Here's what a successful sign-in looks like for outgoing SMTP emails only:

<figure><img src="../../../../.gitbook/assets/CleanShot 2025-10-18 at 07.54.33@2x.png" alt=""><figcaption></figcaption></figure>

Here's the email I received:

<figure><img src="../../../../.gitbook/assets/CleanShot 2025-10-18 at 07.55.59@2x.png" alt=""><figcaption></figcaption></figure>

## TLDR:

Use your @icloud.com email account instead of your custom domain's email or your Apple Account's email address.

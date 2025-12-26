# SSH Certificate Setup

See `My_Gitlab/thoughts/docs/2025-scrapwork/october/20251001.md` for a draft that includes private  notes.

When you want to use Gitlab or Github or connect to systems remotely, it helps to have an SSH key setup. Every security person will tell you to generate a key for every device and don't use the same key across multiple systems, but I say life is too short now that we live in a world where Cloudflare makes me solve puzzles, do 2FA, etc... so in my opinion, I'd rather just encrypt the key and keep them secured across computers unless it's super sensitive.

## Notes

<figure><img src="../../../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/image (480).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/image (483).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/image (526).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/image (538).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../../.gitbook/assets/image (550).png" alt=""><figcaption></figcaption></figure>

## Implementation & Compaibility Error

I got an error when importing my key to the keychains.&#x20;

I used `ssh-add` which never added it to the keychains like my notes say it would & when I tried adding from the GUI, it said my encrypted one at least was not in an appropriate format.

<figure><img src="../../../../.gitbook/assets/image.png" alt="" width="144"><figcaption></figcaption></figure>

I'm going to convert it back into plaintext now. I did that with `ssh-keygen -p -f ~/.ssh/chase-ssh-2021` which decrypted it. (-p is for the password, -f is the output file probably). This failed too.

Google says it's a compatibility error between OpenSSH and older GUI tools like '[Seahorse](https://en.wikipedia.org/wiki/Seahorse_\(software\))' where it needs a different internal header.&#x20;

The file extension does not matter to Linux. The problem is the internal header: `-----BEGIN OPENSSH PRIVATE KEY-----`.

Most modern command-line tools love this format, but many GUI "Import" buttons still only understand the "Classic" (PEM) format, which starts with `-----BEGIN RSA PRIVATE KEY-----`.

{% embed url="https://en.wikipedia.org/wiki/Seahorse_(software)" %}

<figure><img src="../../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

### Sees it, Can't Import It

<figure><img src="../../../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>

The GUI now sees the file and recognizes it from the header; however, it does not let me "import" it. It runs the hash & shows it to me which is cool, but this is infuriating. I have no idea why I can't import it.&#x20;

I think the problem is that it really wants to be called `id_rsa`. And if you have multiple, then id\_rsa.1

So I think the best method is going to take my unencrypted key, put it into this id\_rsa.1 file, and move on with my life.&#x20;

But nope - that didn't work either. It baffles me still. Maybe it needs a `pub` pair.&#x20;

My only guess is that I used some algorithm & key length combination that isn't compatible with Ubuntu. And since I don't recall when I generated my last one and it's healthy to rotate keys, perhaps I'll start over.&#x20;

TODO: test importing this on another Ubuntu machine. And authenticating with Windows ssh agent first too. Then I'll have to update it literally everywhere else which'll suck if I continue down this route.&#x20;

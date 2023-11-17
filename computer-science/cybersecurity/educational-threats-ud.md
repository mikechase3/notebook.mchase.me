# Educational Threats @ UD

## Layered Defense

* Next generation Firewalls
* **F5 Web Application Firewall**
  * All University Web servers are behind this F5.
  * All the web traffic goes to the proxies themselves.&#x20;
  * Decrypts the traffic, look for anything bad, before sending it.
* Network segmentation
  * Students can't access anything else
  * Johnson controls is segmented such that only certain people can access that network.
* EDR/AV
  * Anti-Malware
  * Back when they were using a semantic server on campus, they realized it's a bad idea because people were taking their machines back home.
* Duo 2FA
* **Ivanti/JAMF Desktop Management:** operates Windows & Mac applications and it'll try to keep everyhing up to date.
* Splunk
* Nexpose
* They have a license to collect 100GB of log data for something. Then, if it gets pulled into a central log solution they can start doing checks and vulnerability assessments. It sits in their environment & scans all the servers/appliances and if they're up to date.
* **Aruba Clearpass**: \_\_idk\_\_

<figure><img src="../../.gitbook/assets/image (690).png" alt=""><figcaption></figcaption></figure>

### Information

* Task Force
* CISA
* BitSight
* Security Scorecard
* Ren-ISAC
* Shadowserver
* Shodan
* HavelBeenPwned

### Issues

* COVID & Work from home policies
* VPN/VDIs
* Byod preferences.
* IOT threats.

## June Attack

They sent an email & had people complete a form. The context of the message was that they had two accounts & wanted to consolidate it. The site asked for all sorts of data like usernames & phone numbers. The bad guys love getting into EDU accounts because it's more reputable than a `.com` account and continue their campaign and collect more information in parallel with job scams. They'll try go get people to cash a fake check & then we owe them some money for some reason.&#x20;

Then, with the phone number, they ask for the DUO login code.

## Email

* UD receives 2 million emails each week.
* 91% of cyberattacks begin with spear phishing.
* Gmail dropped most of the incoming mail as spam. Now, very little of the email is dropped for spam.

### Components

* **SMTP Headers**: \_
* **GSuite:** \_
* **DomainTools/Whois:** \_
* **Virustotal:**\_

## Network Threats

1. **DMCA** Copyright violations: every device has a MAC address. The network admission control system has a user log to trace it. Therefore, they know who is doing what.
2. **Threats**: Microsoft & Apple deal with consumers who are interested in privacy rather than security. For example, there's iCloud Private Relay which is a DNS over HTTPS service. If students are going to malicious sites and VPNing away it'll get found.
3. **Mac Address Randomization**: now everytime you log into a website, Windows/Apple will create a pseudo address that's not necessarily tied to your machine. Privacy here is getting in the way of the security procedures they do here.

## Next Generation Firewalls

They basically have an antivirus that'll drop packets based on&#x20;

### Cloud Strike

* The most egregious things packets get sent up and analyzed by others.

## Interesting Incidents at UD

1. 3rd party breaches: Anthem, blackbaud, MOVEit
2. Cheating: students can buy an assignment or an entire class
   1. People have farmed out their entire classes.
   2. Only caught via IT.
3. Server compromised in October 2020. Started bitcoin mining after restoring a snapshot without incidents.
4. Camera in bathroom November 2019. The caught them putting it was caught on the camera he was setting up so he was dumb.
5. 2FA bypass: difficulty of remote identification, Oct 18
   1. Called the helpdesk and faked a lot of info.
   2. Since it was a professor and he was in class, they didn't do anything immediately & the bad guy was in his account for about two hours.
6. Flyers first break in & attempted grade change in December 2013.
   1. The doors had glass paynes
   2. This person would stash his stuff in the bathroom across the hall
   3. Put a keystroke logger. Then, they went back to retreive the keystroke logger. One them saw a keystroke locker with someone was maybe there? They had to investigate what did she do.&#x20;




# Disabling Telemetrics

## Why is this important?

> According to their [privacy policy](https://www.subaru.com/support/privacy-policies.html#additional-disclosures-for-ca-residents), that means things like your name, location, "_Audio recordings of Vehicle Occupants"_, and inferences they can draw about things like your "_characteristics, predispositions, behavior, or attitudes." - Mozilla Foundation on Subaru June 2024_

Nissan shares your sexual activity!

> They come right out and say they can collect and share your sexual activity, health diagnosis data, and genetic information and other sensitive personal information for targeted marketing purposes.
>
> ...
>
> They also say they can share and even sell "Inferences drawn from any Personal Data collected to create a profile about a consumer reflecting the consumer’s preferences, characteristics, psychological trends, predispositions, behavior, attitudes, intelligence, abilities, and aptitudes" to others for targeted marketing purposes. Yes, Nissan says they can infer things like how smart you are, if you have a predisposition to drink, if you are acting depressed, and if you are any good at chess (we're guessing that's what they can infer..it could be even worse than that), and then they say they can make as much money off that very personal information as they can. - Mozilla on Niswsan



{% embed url="https://www.subaruoutback.org/threads/disconnecting-your-telematics-starlink-antenna.519259" %}



{% embed url="https://foundation.mozilla.org/en/privacynotincluded/categories/cars/" %}

##

## Copyright

* This work isn't my own. It was on the forum listed above.
* I'm copying the content in case it goes away.

## Introduction

After a week of trying out my trial subscription to Starlink on my new 2020 Outback, I decided I wasn't getting enough value out of it to justify the security and privacy sacrifices, and cancelled it. However, I plan to go further by physically disconnecting my telematics antennas. If you Google "disconnect Starlink antenna" you'll find a few threads about it on other forums, but not all of them terribly helpful and none of them applicable to the Gen6. So I thought I'd share the results of my research.\\

## Why Disable

\
\
First of all, why am I bothering with this? Exactly what security and privacy am I protecting, and why isn't service cancellation sufficient?\
\
According to the [Starlink privacy policy](https://www.subaru.com/company/starlink-privacy.html) they collect and retain:\\

> vehicle and service-related information, including but not limited to vehicle identification number and description; vehicle maintenance information; mechanical condition or incidents involving the vehicle including crash severity sensor data; time, **location** and speed of vehicle at a time of requested service; your or your vehicle’s occupants’ search content; your personal identification number (“**PIN**”) and information about a call related to the Services or your account, such as the date, time and duration of the call, the identity and phone number of the caller, and contents of or notes about the call. In addition, your vehicle may be equipped with one or more sensing or diagnostic modules capable of automatically retrieving, recording, transmitting, or storing certain vehicle data, including but not limited to trouble codes, tire pressure, battery voltage, coolant temperature, and service requirements. We may collect and retain data from any such modules in your vehicle.

They'll share this information with "suppliers, roadside assistance providers, emergency service dispatchers and providers, anyone you designate as an emergency contact and our affiliates" and also with law enforcement if they receive a subpoena.\
\
None of this is unreasonable or gratuitous; it all seems reasonably connected to the advertised functionality of the product. It's good that they only collect location data in response to crashes or service requests, rather than constantly. It's nonetheless more than I care to share. Even if they're not getting location data all the time I'm driving they're still learning a lot about my driving patterns on the basis of time and mileage. And I don't necessarily want the system automatically calling for help if I get into a minor single car accident; I might prefer to take care of it quietly than to get police and insurance involved.\
\
Cancelling service _presumably_ prevents most of this data collection. But without some significant effort at sniffing bus traffic or reverse-engineering the firmware, I don't really know this for sure. It could be that they're still collecting it all and just no longer giving me access to it. In most of the US, they wouldn't be running afoul of any laws that way.\
\
For sure, though, cancelling service does _not_ prevent Starlink from phoning home. If I wanted to reactivate my service, I could do so without ever touching anything inside the car. The car therefore must necessarily still be connecting to the cell network at least long enough to check up on its subscription status. So at the very least, Subaru is still getting a request containing my VIN every time I turn on my car, and they can use my IP address to deduce my approximate location. AT\&T is getting similar information from my IMSI. I'm of course also leaking this same information to cell providers by carrying a cell phone, but at least that's easy to turn off or leave behind.\
\
That's enough for privacy — how about security? An attacker who takes control of my Starlink account could use it to do some pretty scary things, like immobilize my car in the middle of the highway. Such an attacker could be a rogue Subaru employee or could be anybody who finds a vulnerability in their website or in the unit itself. There have been [many](https://www.bitdefender.com/box/blog/cars/researcher-finds-basic-mistakes-subarus-starlink-service/) such vulnerabilities already discovered, and you should take it for granted that there are more that are not yet known. Cancelling my service doesn't protect from this, since the attacker could just re-enroll me.\\

## Steps to Disable

\
Ok, hopefully I've established that disconnecting your telematics antennas is something worth doing. Now on to how. Unfortunately, it's a giant pain in the ass and if you want to try to do it yourself you're going to at least need the service manual in hand.\
\
There are two separate antennas. The main one is in the sharkfin. But there is also a secondary antenna, referred to in the service manual as the "telematics sub antenna", located behind the instrument panel. I'm not sure if the second antenna is just there for redundancy (in case the main one gets destroyed in a crash) or if they're tuned to different bands. The manual refers to them both as LTE antennas but it would make sense if the sub antenna were actually UTMS (3G). Regardless, they both need to go.\
\
The path from the main antenna to the data communication module (where the transceiver is) passes through three different connectors, and one of them is easy to get at. It plugs into an antenna amplifier located at the top of the lift gate, which you can get to just by popping off the trim panel with your fingers or a plastic pry tool. This is the one labeled "An63" in the service manual. If it weren't for also having to do the sub antenna, I'd do this one myself and post a howto video. Sadly, the sub antenna is much harder to get to and I don't dare attempt it on my own (dammit Jim, I'm a security researcher, not a mechanic). There's only one connector, "An65", and you have to pull out the whole instrument panel in order to reach it. Nope, not gonna do that to my new car.\
\
However, I've explained to my dealer's service department what I want done, and they're willing to do it. My appointment is March 2, and I'll update this thread afterward and let you know about any problems I encounter or the lack thereof. I'm not expecting any. It's just an antenna after all, and sometimes an antenna isn't going to have any signal, so the car must be designed to cope with that.\
\
UPDATE 2020-03-02: Success! See [this reply](https://www.subaruoutback.org/threads/disconnecting-your-telematics-starlink-antenna.519259/page-3#post-5946760) for how the dealer went about it and what the outcome was.

## Effects

Unknown.

## More Threads/Info

> I also temporarily disconnected the white wire harness on the top right side of the head unit that connects to the top control console.\
> \
> This took me five minutes. I moved slowly from the top corner of the trim pieces and worked down and to pop the trim lose enough to remove by hand.\
> \
> 2\. Carefully disconnected the wire harnesses and antennas connected to the telematics unit (it is black box on the top of the head unit stack). This was the hardest part.\
> \
> The two left gray wire harnesses have a snap/tab on the bottom which must be pushed in fully while pulling out the harness.\
> \
> The four antenna harnesses (light grey, green, brown and dark grey) have one snap/tab on the bottom which is very easy to push in and remove the harness.\
> \
> 3\. Plugged in the AutoHarnessHouse Starlink Bypass Plug to cross over the front speaker wires on the second gray wire harness.\
>
>
> #### [Bypass the Subaru Starlink Tracking & Front Speaker fix](https://www.autoharnesshouse.com/69018.html)
>
> If you would like to bypass the communication functions in your Subaru or if you're having trouble with the Starlink Telematics unit draining your battery, this will be your solution! This adapter allows all telematics functions to be bypass on newer Subaru vehicles - We custom build these to...www.autoharnesshouse.com\
> I did not need this, but for convenience I spent the $40; a bit pricey for what it does which effectively crosses over the two purple wires to each other, two blue wires, two pink wires and two light blue/greenish speaker wires.\
> \
> This is because the telematics needs speaker connection to make its announcements. Without the cross over, the front speakers will be effectively disconnected.\
> \
> This is where I could stop, and put everything back together, but I continued.\
> \
> 4\. Removed the telematics unit.\
> I did not need to do this, but I removed the telematics unit by removing the four screws that holds it into the head unit bracket (two screws on each side) - similar to removing a hard drive from a PC.\
> \
> I opened the telematics unit to check it out - it looks to be produced by Continental "Conti Model A3C0310450100".\
> \
> The only thing I did was removed the backup lithium battery that keeps the unit powered after the car is turned off.\
> \
> 5\. Put everything back together in reverse.\
> \
> The entire process took 20 - 30 minutes (I had some interruptions).\
> \
> Tools I needed:\
>
>
> * plastic trim removal tools
> * 10mm socket wrench and
> * a torex screw driver (forgot the size).
>
> \
> The most difficult step was pushing the two tabs in the bottom of the gray wire harnesses while pulling this out of the back of the telematics unit.\
> \
> Lastly, for those who ask why go through all this effort? I personally don't want to use the Starlink services and even when I have opted out, they continue to collect data. Subaru should have an easy way to completely turn off their data collection - e.g., GM Onstar - just pull the fuse, although there should be a switch.

# Prep Test

## What are the main responsibilities of the Network Layer?

* Routing
* Port forwarding. Move the packets to the outgoing port.

## Delays

### Propagation Delay

* Time that a packet propagates out of the links from the sender to the receiver.

$$
\frac{d \text{ (The distance of the link in meters)}}{s \text{ (The propagation speed in meters/second)}}
$$

### Transmission Delay

* The time it takes for a packet to travel on a link.

$$
\frac{L \text{(The thing)}}{R \text{(in bits per second.)}}
$$

## Queue Growing Math

### Part B

### Part C

The queuing will only happen with 2 or more users are transmitted.

#### What is the fraction of the time which the queue grows?

## Links

![](<../../.gitbook/assets/image (365).png>)

#### What is the end-to-end delay of sending a packet of length L = 1000 bytes? (Ignore propagation delay and processing delay)

$$
\frac{L}{R} = \frac{1000 \text{ bytes} \times 8 \text{ bits}}{2,000,000 \text{ bits per second}}
$$

The final answer works like this

$$
\frac{L}{R_1} + \frac{L}{R_2} + \frac{L}{R_3} = \frac{8000 \text{bits}}{6 \text{mbps}} + \frac{8000 \text{bits}}{2 \text{mbps}} + \frac{8000 \text{bits}}{4 \text{mbps}} = \frac{8000 \text{bits}}{1 \text{mbps}} (\frac{1}{4} + \frac{1}{6} + \frac{1}{2})
$$

#### Suppose a file has 5M bytes. Estimate how long it takes to transfer the file to the receiving host.

![7 sec + 20 seconds + 10 seconds to push the whole file onto the 3rd link.](<../../.gitbook/assets/image (366).png>)

## HTTP Thing

*

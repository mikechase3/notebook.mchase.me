# Splines & Roller Coaster Notes

Splines are a way to place objects along a mathematical equation such that they are efficient in memory. It's composed of two vectors on a cartesian plane, but an equation controls the shape giving it a curve.

<figure><img src="../../../.gitbook/assets/image (701).png" alt=""><figcaption></figcaption></figure>

## Roller Coastr Assignment Requirements

* Design based on Spline and Unity physics.
* Include up and down, turn left and right, and twist.
* Trigger screaming with trigger boxes.
* Must be on mobile (Google Cardboard recommended).
* Add sound, water splash, fire, landscape, and explosion for bonus points.

## Spline Underlying Math

It's easier to read about it elsewhere, but here's my notes:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-09 at 14.18.53@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-09 at 14.19.29@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-09 at 14.19.45@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-09 at 14.20.00@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-09 at 14.20.13@2x.png" alt=""><figcaption></figcaption></figure>

## Roller Coaster Assignment

### Class Feb 27, 2024

* Provided tools in a zip file and outlined requirements.
* Assignment: Make roller coaster last 30+ seconds after the chain and hill.

### Introducing Splines

* Joint editor for spline adjustments.
* Adding "knots" to form the spline.

### Class Feb 29, 2024

* Started working on the `SplineFollow` script.
* Discusses realistic variables and equations.
* Acceleration as the second derivative.
* Engine moves the car; `Booster.cs` used instead of `MoveCar`.
* Waypoints: Old-fashioned method discussed.
* Created waypoints and encountered an error.
* Waypoint mover script introduced.
* Only need the Waypoints script attached to the root, not the children.

### Moving the Car

<figure><img src="../../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

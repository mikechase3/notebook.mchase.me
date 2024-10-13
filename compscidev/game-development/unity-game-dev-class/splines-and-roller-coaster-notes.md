# Splines & Roller Coaster Notes

## Project Setup

Link to the project in zip form:

{% embed url="https://drive.google.com/file/d/1Mcp3uJ-larCEAf72oCdyh7P-WJPccXoc/view?usp=sharing" %}

## What Are Splines?

Splines are a way to place objects along a mathematical equation such that they are efficient in memory. It's composed of two vectors on a cartesian plane, but an equation controls the shape giving it a curve.

<figure><img src="../../../.gitbook/assets/image (701).png" alt=""><figcaption></figcaption></figure>

## Roller Coaster Assignment Requirements

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

<figure><img src="../../../.gitbook/assets/image (13).png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

## Scripting

This is a first-pass of me reading the provided scripts.&#x20;

### Booster Script

Essentially, this script applies a nudge to help maintain the speed of GameObjects passing through the trigger zone, playing sound on repeat while it stays in the trigger zone, and stops both as it exits. Skip to the next header now.

```csharp
    private void OnTriggerStay(Collider other)
    {
        // Check if the collision involves a Rigidbody component
        Rigidbody otherRigidbody = other.gameObject.GetComponent<Rigidbody>();

        if (otherRigidbody != null)
        {
            // Calculate the current speed of the object
            float currentSpeed = otherRigidbody.velocity.magnitude;

            // Check if the current speed is below the minimum
            if (currentSpeed < minimumSpeed)
            {
                // Apply force continuously as long as the object stays in the trigger
                otherRigidbody.AddForce(forceMagnitude * other.gameObject.transform.forward);
                

                // Check if the audio source is not playing, and if not, play the sound
                if (!audioSource.isPlaying)
                {
                    audioSource.Play();
                }
            }
        }
    }

    private void OnTriggerExit(Collider other)
    {
        // Stop playing the sound when the object exits the trigger zone
        audioSource.Stop();
    }
```

<details>

<summary>Jibber Jabber </summary>

When a game object collides with a trigger box, you can use the `OnTriggerStay (Collider other)` to run custom code through that function because it inherits Monobehaviour. Because we have a reference to that object, we can grab it's rigidbody. Rigidbodies give them mass such that they react to the laws of physics and we can assign them a mass. Because they have mass, we can make them react to other game objects which have mass because they are rigid bodies. The `Booster.cs` shares the game object with the trigger box, so we'll grab it and change it's speed by applying "forward".

Forward by my rough definition on the x-z axis. I should lookup what's the proper term. I'll do this by messing around with it. Let's look at this existing code & print what `transform.forward()` is:

```
// Apply force continuously as long as the object stays in the trigger
otherRigidbody.AddForce(forceMagnitude * other.gameObject.transform.forward);
```

And once again I forgot how to print stuff to the console so I'll save this for when it's an actual problem & come back to it. I believe it'll be forward on the x-z plane of whatever we define to be the front (which is the front of the roller coaster). Just use common sense in orienting things.&#x20;

First, the forceMagnitude variable holds however much force is applied to that other game object's rigidbody. I wonder - is there a convention for books? Am I referring to the class? Like... yeah, but really an instance of a game object defined by the class. Interesting conundrum for a fellow commenter. `miniumSpeed` is just a float. You can put a sound clip in here too, that's nice.&#x20;

When we start the script, it'll add an audio component to itself & set the sound to play continuously in a loop until `OnTriggerExit());`

</details>



### Spline Follow Script

Engine is the only game object in the provided scene that uses the game object. The engine spawns the car mesh and somehow glides it along the spline.&#x20;

Recall that an engine has the following **components**: rigidbody, box collider, audio files, booster script, and this spline follow script. We'd expect this to be in the beginning as a puiblic/serializable field and there's almost too many to keep track of holy moly:

```
    Rigidbody rb;
    GameObject car;
    [SerializeField] SplineContainer track;
    // [SerializeField] GameObject car;
    public float directionSwitchThreshold = 0.3f;
    public float velocityDampeningThreshold = 2.5f;
    public float velocityDampeningRate = 0.8f;
    public float stopMinAngleThreshold = 12f;
    public bool isFollowingSpline = true;

    //Information about our object.
    [SerializeField] private Vector3 velocity;
    [SerializeField] private float velocityMagnitude;
    [SerializeField] private float direction;
    [SerializeField] private float angle;
    [SerializeField] private bool movingBackward = false;

```

The `Start()` method gets the rigidbody component of itself which is the car. Update() will run & updates to the nearest point along the provided spline through and match the forward/up position tangent to the spline.

### Spline Transform Notes

We're going to apply a 200x200 offset in the x/z axis to keep the track on the terrain at 0,0 without having to re-draw the beginning of the spline.&#x20;

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-10 at 01.07.48@2x.png" alt=""><figcaption></figcaption></figure>

## Building the Track



I started by using a top-view and drawing the different points & stopped after a few after noticng that I wasn't reaching the top. I figured there might be a little friction, but I'm only reaching halfway up the other spline:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-10 at 14.08.54.gif" alt=""><figcaption></figcaption></figure>

Easy fix I thought. If we dial up the mass, then the momentum will make the coefficient of friction negligable.

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-10 at 15.28.55@2x.png" alt=""><figcaption></figcaption></figure>

Unfortunately, the orcale says:

> Mass does not affect inertia: In the real world, a heavier object would have more inertia and thus could climb higher given the same initial speed. However, in Unity's physics system, mass does not affect inertia in the same way. Gravity affects all objects equally, but friction and drag can be affected.

In the engine's rigidbody, I set these back to zero:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-10 at 15.40.00@2x.png" alt=""><figcaption></figcaption></figure>

I honestly didn't think that would work, but that was it:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-10 at 15.41.07.gif" alt=""><figcaption></figcaption></figure>

### Constructing the Track

First, take a cube. I scaled mine to look like an `H` like so:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-11 at 17.15.10.png" alt=""><figcaption></figcaption></figure>

Next, I modified the script to include this to make the track follow the spline.&#x20;

```csharp
[SerializedField] prefa;

void placePrefabsAlongSpline() {
    if (track.Spline == null || prefab == null) {
        return;
    }

    float totalDistance = track.Spline.GetTotalLength();
    int n = Mathf.RoundToInt(totalDistance / resolution); // where resolution is the desired distance between prefabs

    for (int i = 0; i <= n; i++) {
        float t = i / (float)n;
        Vector3 position = track.Spline.EvaluatePosition(t);
        Vector3 tangent = track.Spline.EvaluateTangent(t);
        Quaternion rotation = Quaternion.LookRotation(tangent);
        
        Transform instance = Instantiate(prefab, position, rotation);
        instance.SetParent(track.transform);
    }
}


```

And now it works. I had to re-adjust some of the sharp turns.

<div align="left">

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-11 at 17.13.37.png" alt="" width="187"><figcaption></figcaption></figure>

 

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-11 at 17.21.27.png" alt=""><figcaption></figcaption></figure>

 

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-11 at 17.32.33.gif" alt=""><figcaption></figcaption></figure>

</div>

### Eliminating Collisions

Let's just move the track down & see what happens?

![](<../../../.gitbook/assets/CleanShot 2024-03-11 at 17.59.32@2x.png>) So now that it's moved down we get:

<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-11 at 17.57.43.png" alt=""><figcaption></figcaption></figure>

## Audio Triggers

### Prefab Reference Approach (Didn't Work)

While I don't know the right approach, this should work:

```
public AudioSource audioSource;
public AudioClip scareClip;
public GameObject scareBox;  // WORKING ON IT
```

And for the function:

```
    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject == scareBox)  
        {
            // Ensure AudioSource isn't already playing something
            if (!audioSource.isPlaying)
            {
                audioSource.PlayOneShot(scareClip);
            }
        }
    }
    
```



<figure><img src="../../../.gitbook/assets/CleanShot 2024-03-12 at 10.22.21@2x.png" alt=""><figcaption></figcaption></figure>

### Tag Approach

Don't know what's up with that, but let's try this. Same thing, but instead of using the object we'll compare tags:

```
    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("scaryAudioBox")){
            // Ensure AudioSource isn't already playing something
            if (!audioSource.isPlaying)
            {
                audioSource.PlayOneShot(scareClip);
            }
        }
    }
```

## Building for Google Cardboard VR

Build for AR w/ android support for google cardboard.

{% embed url="https://developers.google.com/cardboard/develop/unity/quickstart" %}

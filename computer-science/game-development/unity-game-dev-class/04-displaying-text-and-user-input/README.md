# 04 Displaying Text & User Input

## Displaying Text

* Text gets added to the `canvas`, which is a weird way to say die.&#x20;
* When you add text, the largest font size supported in Unity is 27pt. It used to be 36pt (which broke lots of games).&#x20;
* If you try to exceed it, it'll break the games.
* You can make it larger; however, when you make the text 5x bigger is because it took the pixels of a 27pt font and the pixels merge/blur with adjacent pixels. This makes text look blurry.

![](<../../../../.gitbook/assets/image (644).png>)

### Springs and Struts

* These are old school. We use Autolayout nowadays in modern apps, but these give you a lot control.
* Items you place will be `x` many pixels away from this point.&#x20;
* If you use a stretch option, it'll base it off of 2 or 4 points and keep the distance constant (while sacrificing the middle).&#x20;

![](<../../../../.gitbook/assets/image (646).png>)

### Updating Text via Scripts

1. Attach a script to any game object. (Not the text or canvas... but maybe you can. Haven't tested it myself.)
2. Write a script for it (example below)
   1. Ensure there's a public `UnityEngine.UI.Text` object so Unity can map the text to your script.
   2. You'll access this by using `<var>.text = "some_string"`
3. Drag the _Text UI Object_ into the variable placed on that script.

For example:

{% code title="HitCounter.cs" %}
```csharp
using UnityEngine;

public class HitCounter : MonoBehaviour
    int counter = 0;
    public UnityEngine.UI.Text scoreText;  // Now lets you attach it externally.
    
    
...
void Update(){
    counter += 1;
    ScoreText.text = counter.ToString
}
```
{% endcode %}

![Step 3: drag a text UI object from hierarchy](<../../../../.gitbook/assets/image (640).png>)

## Displaying Two Tone Text

Roughly the same outline as above, but a bit more sophisticated. Here's the steps:

* Create an empty  `GameObject`and call it `TwoToneText`.
* Place two texts at position `{0, 0, 0}` in the `Rect Transform` properties (in the inspector).
* Slightly offset one to the right and up slightly.
* _Fun Fact: the mars rover's parachute didn't deploy due to a mixup between feet and meters. It left a crater instead instead of a scientific research project._

![](<../../../../.gitbook/assets/image (645).png>)

In the script, well have to modify it to control both. A more scalable way to do this is to make a script which controls both the foreground & background text.

{% code title="TwoToneText.cs" %}
```csharp
using System.Collections;
using UnityEngine;

public class TwoToneText : MonoBehaviour{
    public UnityEngine.UI.Text foregroundText;
    public UnityEngine.UI.Text backgroundText;
    
    // Setter
    public void SetText(string s){
        backgroundText.text = foregroundText.text = s;
    }
}
      
```
{% endcode %}

Now, we can go back into our first file in `HitCounter.cs` and reference the `TwoToneText` class by instantiating it within `HitCounter.cs` like so:

```csharp
public class HitCounter : Monobehaviour
    int counter = 0;
    //OLD: public UnityEngine.UI.Text scoreText;
    public TwoToneText scoreText;

    
    //Start is called before the first frame update
    void Update(){
        counter +=1;
        //OLD: scoreText.text = counter.ToString();
        scoreText.SetText(counter.ToString());
    }
}
```

Connect the `scoreText` variable in Unity like so:

&#x20;&#x20;

![Under the game object you chose](<../../../../.gitbook/assets/image (642).png>)

![Under the 'TwoToneText' instance's paramsO](<../../../../.gitbook/assets/image (643).png>)

## Frame Rates & Update()

{% embed url="https://docs.unity3d.com/ScriptReference/Application-targetFrameRate.html" %}

* Update() gets called right before each frame update.
* As long as a method can keep up with that frame rate, the function will be called.
* If your drawing takes too long and isn't finished in a 60th of a second window, it has to wait until the next 60th of a second (essentially dropping you to 30fps).
* If you miss 2 times, you're down to 20fps. If you're down 3, you get 15fps. If you're down 4, then 10. These are the increments of measurements for what happens when you can't draw the frame in time.



## Getting Input

For testing, it's easy to get input:&#x20;

```csharp
In.GetKey("space"))
```

However, you should use input mapping.&#x20;

## Collisions

{% embed url="https://docs.unity3d.com/ScriptReference/Collision.html" %}

There's two ways to figure out what objects are colliding with each other:

### Comparing Strings

![](<../../../../.gitbook/assets/image (638).png>)

### IsTrigger

* Make sure you turn this on and read up about triggers.

![](<../../../../.gitbook/assets/image (641) (1).png>)

## Debugging

```csharp
UnityEngine.Debug.Log(<variable>);
```

## Send Message Upwards

See example. Lecture 04. 01:10.

{% embed url="https://docs.unity3d.com/ScriptReference/Component.SendMessageUpwards.html" %}
Send Message Upward Sends Messages to Parents
{% endembed %}



{% hint style="warning" %}
Ask for help/clarification about this (L04: 1:11)
{% endhint %}

* Coupling is bad.
* If you can't change one thing and can't change something else, it "smells"
* To decouple the TwoToneText, we'll do this, we'll use the `SendMessageUpdward()` function.
* This starts with your parent and every ancestor above that and see if it can make sense of it.
* Now, you don't need the public two tone text because it'll just be sent to the parent class.

{% code title="HitCounter.cs" %}
```csharp
using blahblahblah
public class HitCounter : MonoBehaviour{
    int counter = 0;
    // Upon collision with another GameObject, this GameObject will reverse direction
    void OnCollisionEnter(Collision collision){
        counter += 1;
        sendMessageUpward("ChangeScore", counter.ToString());
    }
}
```
{% endcode %}

To receive the message, we'll need to nest Game Logic under it. Inside our Game Logic. Make sure to hook it up to something higher in the hierarchy than `TwoToneText`.&#x20;

{% code title="GameLogic.cs" %}
```csharp
public class GameLogic : MonoBehaviour{
    public TwoToneTextObject scoreText;
    
    void Start(){
        if (null != scoreText){  // If scoreText exists
            scoreText.SetText("0");
        }
    public void ChangeScore(string s){
        UnityEngine.Debug.Log(s);
    }
}
```
{% endcode %}






# Stable Matching Problem

For CPS 530 Week 2. **Goals**: sets up issues in algorithm design.

## Sources:

I used a multitude of videos to understand this. I'd start there if you're learning it yourself.

1. [UW CSE442 Visualization Site](https://uw-cse442-wi20.github.io/FP-cs-algorithm/)
2. [Numberphile](https://www.youtube.com/watch?v=Qcv1IqHWAzg)'s explanation without math.
3. [Numberphile w/ Math](https://www.youtube.com/watch?v=LtTV6rIxhdo).
4. MIT's Mathematics for Learning Library.
   * [MIT Stable Marriage Problem Reading](https://openlearninglibrary.mit.edu/assets/courseware/v1/d654c70d7bd563a57216f76bd8bbf308/asset-v1:OCW+6.042J+2T2019+type@asset+block/MIT6\_042JS15\_Session22.pdf)
   * [MIT Open Learning Library](https://openlearninglibrary.mit.edu/courses/course-v1:OCW+6.042J+2T2019/courseware/2123f967fa994ff8a6d8bb681df65745/c722e6fd7da7492d9e165a6c987898e5/?activate\_block\_id=block-v1%3AOCW%2B6.042J%2B2T2019%2Btype%40sequential%2Bblock%40c722e6fd7da7492d9e165a6c987898e5)
   * [6.042J](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-fall-2010/pages/syllabus/) MIT. Especially the [Recitation notes](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-fall-2010/resources/mit6\_042jf10\_rec07\_sol/).
   * [Stable Matching Ritual](https://www.youtube.com/watch?v=RE5PmdGNgj0)

## Questions for Review:

1. Describe the stable marriage problem.
2. What is a perfect match?
3. What is an unstable pair?
4. Know the proof of termination.
5. Know the proof of correctness
6. Write the proof of stability
7. Write an efficient implementation.

## The Gale-Shapley Deferred Acceptance Algorithm (1962)

```
algorithm stable_matching:
		Initialize all men and women to free (unengaged)
		while there exists a free man m who still has a woman w to propose to:
			set w to first woman on m's list to whom m has not yet proposed
			if w is free:
				(m, w) become engaged
			else:
				let m' be w's current fiance
				if w prefers m to m':
					m' becomes free
					(m, w) become engaged
				else:
					(m', w) remain engaged
```

## Scrap Notes

<figure><img src="../../../.gitbook/assets/Stable Matching Scrap Notes.png" alt=""><figcaption></figcaption></figure>

## Class Notes

### Background

* Sweeden awarded them via the Royal Swedish Nobel of Economics and something in Harvard.

### Brute Force Approach

<figure><img src="../../../.gitbook/assets/image (149).png" alt=""><figcaption></figcaption></figure>

Another example:

<figure><img src="../../../.gitbook/assets/image (266).png" alt=""><figcaption></figcaption></figure>

## How to Prove Correctness

* **Deterministic**: this algorithm always produces the same result.

#### Termination

* **Observation 1**: men propose to women in decreasing order of preference.
* **Observation 2**: once a woman is matched, she only trades up & is always single.
* **Claim**: the algorithm terminates after at most `n^2` iterations.

#### Perfection

* **Claim**: In Gale-Shapley matching, all men & women get matched.
* Proof is by contradiction
  * Suppose for sake of contradiction, that Zeus isn't matched upon termination of the GS algorithm.
  * Then, there is a single girl must be unmatched & Zeus didn't propose to Amy.
  * Therefore, this contradicts the condition for the while loo because our counter-claim can't be true (that Amy never received a proposal and that cannot happen).

#### Stability

* **Claim**: in Gale-Shapley matching, there are no unstable pairs.
* **Proof**: by **contradiction**.
  * Let's say that for sake of contradiction, it's possible for there to be an unstable pair after the algorithm gets completed.
  * We did an example on the board. See one of the above sources for the proof of stability.

### Efficient Implementation

* We describe an O(n^2) time implementation
* Assume men are named {1, ..., n}
* And the women are {1', ... n'}
* Maintain a list of free men in a stack or queue.
* Maintain two arrays `wife[m]` and `husband[w]`.
  * If `m` matched to `w` then `wife[m] = w` and `usband[w] = m` set entry to 0 if unmatched.

### Proof that women get the worse deal

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

#### Unorganized

Proof by contradiction?

![](../../../.gitbook/assets/partners.png)

## Homework & Implementation

Search my hashmap for `MatchingCPS530` folder. It's currently sitting in the default PyCharm project dir. I took the non-report aspects of the code & put it on Replit; however, there are optimized implementations online elsewhere that don't use my `Person` class and just use straight-up lists.

{% embed url="https://replit.com/@mikechase3/Stable-Matching-CPS-530-UDayton?v=1" %}

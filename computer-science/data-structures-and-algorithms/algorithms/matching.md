# Matching Algorithms
For CPS 530 Week 2.

## Sources:
I used a multitude of videos to understand this. I'd start there if you're learning it yourself.
1. [UW CSE442 Visualization Site](https://uw-cse442-wi20.github.io/FP-cs-algorithm/)
1. [Numberphile](https://www.youtube.com/watch?v=Qcv1IqHWAzg)'s explanation without math.
2. [Numberphile w/ Math](https://www.youtube.com/watch?v=LtTV6rIxhdo).
3. MIT's Mathematics for Learning Library.
   * [MIT Stable Marriage Problem Reading](https://openlearninglibrary.mit.edu/assets/courseware/v1/d654c70d7bd563a57216f76bd8bbf308/asset-v1:OCW+6.042J+2T2019+type@asset+block/MIT6_042JS15_Session22.pdf)
   * [MIT Open Learning Library](https://openlearninglibrary.mit.edu/courses/course-v1:OCW+6.042J+2T2019/courseware/2123f967fa994ff8a6d8bb681df65745/c722e6fd7da7492d9e165a6c987898e5/?activate_block_id=block-v1%3AOCW%2B6.042J%2B2T2019%2Btype%40sequential%2Bblock%40c722e6fd7da7492d9e165a6c987898e5)
   * [6.042J](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-fall-2010/pages/syllabus/) MIT. Especially the [Recitation notes](https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-fall-2010/resources/mit6_042jf10_rec07_sol/). 
   * [Stable Matching Ritual](https://www.youtube.com/watch?v=RE5PmdGNgj0)

 
## Questions for Review:
1. Describe the stable marriage problem.
2. What is a perfect match?
3. What is an unstable pair?
4. Know the proof of termination.
5. Know the proof of correctness
6. Write the proof of stability
7. Write an efficient implementation.

## The Algorithm
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


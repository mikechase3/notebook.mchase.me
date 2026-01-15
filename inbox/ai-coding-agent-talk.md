# AI Coding Agent Talk

## Common Mistakes

1. One-shot attempts don't work. Instead - do problem decomposition.
2. Not respecting the context window.
   1. Once you get to about 60% of the context window, you. start seeing hallucinations & a worse experience.
3. Not having ground Rules - the claude.md, agents.md.&#x20;
   1. Most products are using agents.md
   2. It's a working agreement with your coding agreement. This is what I care about, etc.&#x20;
4. Telling the agent to code.
   1. Dictating the exact code to write isn't a good approach.&#x20;
   2. Instead, tell it the goal & lelt it colllaborate with it. Ask about the different options we have.
   3. Maybe what the human thought of isn't the best way & there's another/better way. Help it solve the problem with you and collaborate with it.&#x20;

## Old vs. New Habits

1. For task management, he liked a user story. A markdown file with a todolist and when he finds something else he wannts to do that,&#x20;
2. NOW, he has todo lists with ASCII wireframes.&#x20;
3. Incremeental development with agent collaboration
4. Rapid integration cycles with instant feedback
5. Seek advice of agent's ast wealth of knowledge.

You can also tell it to "be honest" because they lie to you all the time, but if you tell it to be honest it'll think you can just do that.

### Commit Discsipline

**Old:** instead of using microcommits, occasional rollbacks. less idscipline, do the new thing.

**New:** commit once the code works. Must be able to rollback changes quickly because agents create messes fast.&#x20;

### Learning & Experimentation

**Old:** careful experimentation, code attachment, and cautious iterations.

**New:** do more rapid experimentation, throw away code easily, and keep learnings but ditch implementation.&#x20;

### Software Craftsmanship

1. Well crafted software
2. Steadily adding value
3. A community of professionals
4. Productive partnerships

This is a movement to prioritize:

1. CQuality
2. Community
3. Incremental business value

XP Practices like:

1. TDD
2. Continous integration
3. Refactoring
4. Social Programming

{% embed url="https://manifesto.softwarecraftsmanship.org/" %}

## Stock Tracker App (Example)

Diamante Investments is what this speaker wrot years ago.We're going to add more stats about the stock.&#x20;

What it is:

1. Modern web platform for real-time stock tracking
2. Mobile optimized for retail value.

### Taming the Agentic Drtagon

This is as cycle.

1. Ground rules
2. Planning
3. Context Window Management
4. Predictive TDD
5. Agent/Human final review

### Universal Ground Rules

Don't repeat yourself in every chat. Give your agent rules. This is one for ALL projects and you can use this universially.&#x20;

```
GUIDELINES
Always start your answers with a starter_symbol. The default starter_symbol is <EMOJI>
Be productive and flag issues before they become a problem.
When reporting information to me, be extremely concise and sacrafice grammar for the sake of concision.
Write readable and expressive code that does not need redundant comments or reasoning why something changed.
Follow snigle responsibility principle
Methods should not be longer than 25 lines.
Prefer value objects in an object-oriented codebase
Prefer strong types and pure functions in functional codebases
Prefer small reusable functions and pure functions unless handling outer shell I/O dependencies
Proactively scan available skills & invoke relavant ones for each task
After completing tasks that used skills, suggest improvements to those skills.

```

For the first one, to start it with an emoji, this is a test for the LLM. And if it stops following this rule, it will not. It rarely follows the 25-line code. Use linting rules to enforcing that. Say there's an error if it exceeds 40 lines. Pre-commit hook something, it runs the linting, and then it fixes it.&#x20;



### Project-Specific Rules

These should be not written in stone. Any of the ground rules should be ever-evolving. In this react project, we have:

1. TDD Process for new features
2. Story implementation
3. Acceptance Test Guidelines
4. Helper Naming Convention
5. Helper Extraction Criteria

Example Test:

```

test('user searches invalid ticker and sees no matches message prview, async() => {
    givenSearchReturnsNoMatches();
    render(<App />);
    whenUserTypesInSearch('INVALID123');
    await thenUserSeesMessage(/no matches found/i);
}
```




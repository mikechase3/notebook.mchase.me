# Decorators

## Resources



{% embed url="https://realpython.com/primer-on-python-decorators/#syntactic-sugar" %}

##

## staticmethod

```
class Person:
    name: str = ""
    prefs: List[str]
    curSpouse: str = ""

    def __init__(self, name: str, prefs: List[str]):
        self.name = name
        self.prefs = prefs

    def __repr__(self):
        temp = "{}; Prefs: {}; curSpouse: {}".format(self.name, str(self.prefs), self.curSpouse)
        return temp

    def propose(self, name: str):
        if name not in self.prefs:
            raise ValueError("ERROR:  " + name + " is not in " + self.name + "'s preference list")
        else:
            raise NotImplemented("Error")
        
    @staticmethod
    def prefers(self, other_person: str, current_partner: str) -> bool:
        """
        Returns True if the person prefers the other person to their current partner,
        and False otherwise.

        Args:
          other_person: The name of the other person.
          current_partner: The name of the person's current partner.

        Returns:
          A boolean value indicating whether the person prefers the other person to
          their current partner.
        """

        # Check if the other person is in the person's preferences list.
        if other_person not in self.prefs:
            raise ValueError("{} is missing from {}'s partner list. Ensure all names are in everyone's pref list.")

        # Check if the other person is higher in the person's preferences list than
        # their current partner.
        other_person_index = self.prefs.index(other_person)
        current_partner_index = self.prefs.index(current_partner)

        return other_person_index < current_partner_index
```

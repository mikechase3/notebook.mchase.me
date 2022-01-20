# Entity Relationship Model

## Terminology

![](<../../../.gitbook/assets/image (585).png>)

* **Entity**: objects in the world with an _**independent existence**_. Distinguishable from other objects.
* **Relationships**: are how things interact.

| Term                    | Description                                                                          | Example                                                                         |
| ----------------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------- |
| Entity                  | Objects in the real-world with an independent existence.                             | ![](<../../../.gitbook/assets/image (589).png>) The entity goes in a rectangle. |
| Attribute               | Some property of an entity.                                                          |                                                                                 |
| Composite Attribute     | An attribute composed of several more basic attributes.                              | A `person` could be composed of a name, DOB, etc.                               |
| Single-Valued Attribute | An attribute composed of only a single value.                                        | An ID is just a number and probably isn't composed of different things.         |
| Derived Attributes      | An attribute whose value can be derived from other another attribute                 |                                                                                 |
| Key Attribute           | Any attribute for an entity whose values are unique for each instance of the entity. | It must be **unique** and used to pull someone from the database like an ID.    |
| Domain                  | Set of values that can be assigned to an attribute, for each individual identity.    | GPA has domains of 0 to 4.                                                      |

## Relationships

Relationships are placed in diamonds.

![](<../../../.gitbook/assets/image (584).png>)

## Roles

![](<../../../.gitbook/assets/image (590).png>)

* **Roles** tell you more about the relationship beyond what's in the diamond.
* Roles are straightforward/obvious, except in **recursive relationships**.&#x20;
  * Therefore, you need to put `father` and `son` to see what each is referring to.

## Structural Constraints

* **Cardinality Ratio Constraint**: specifies the number of relationship instances that an entity can participate in.
* **Participation Constraints**:&#x20;
  * **Total (Existence Dependency)**: Every entity in _the total set_ of employee entities must be related to a department entity via works-in.
  * **Partial:** Some or part of the set of employees are related to the department via a manager, but not necessarily all.

![For a department to exist, there has to be an employee managing it; not every employee is a manager.](<../../../.gitbook/assets/image (588).png>)

## Weak Entities

* A **weak identity** for each relationship is identified by considering the primary key of another (owner) identity.
  * it's attached to its identifying owner.
  * The **double diamond (or bold diamond)** shows the **identifying relationship**.
* Whenever there is a weak entity, there is always going to be an existence dependency.&#x20;

![ssn is a primary key. ](<../../../.gitbook/assets/image (591).png>)

**In this example...**

* Key: social security number for employees.
* Dependence is a weak entity. It cannot exist without a relationship with the other entity.
* `pname` is a **partial key.**
* Identifying relationship: policy. It connects the employee with the dependent.

## Superkeys

* A **superkey** is any set of attributes that uniquely identify a row.
  * If a key just had `{course#,section#}`, it would be a primary key because it has enough information to uniquely identify it.
  * A super key would be `{course#,section#,room#}`. It is super because it contains _all_ the information, beyond what is needed.
* A superkey for which no subset is also a superkey is a **candidate key**.

{% hint style="info" %}
Ask Prof. Buckley to check accuracy here regarding the specific definitions. Does a super key need _all_ that information? Or just some of it? What makes it super? And what is a candidate key?  Why is it called that?
{% endhint %}

## Example

![](<../../../.gitbook/assets/image (592).png>)


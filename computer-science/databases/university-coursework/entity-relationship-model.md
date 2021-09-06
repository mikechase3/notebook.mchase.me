# Entity Relationship Model

## Terminology

![](../../../.gitbook/assets/image%20%28585%29.png)

* **Entity**: objects in the world with an _**independent existence**_. Distinguishable from other objects.
* **Relationships**: are how things interact.

| Term | Description | Example |
| :--- | :--- | :--- |
| Entity | Objects in the real-world with an independent existence. | ![](../../../.gitbook/assets/image%20%28589%29.png) The entity goes in a rectangle. |
| Attribute | Some property of an entity. |  |
| Composite Attribute | An attribute composed of several more basic attributes. | A `person` could be composed of a name, DOB, etc. |
| Single-Valued Attribute | An attribute composed of only a single value. | An ID is just a number and probably isn't composed of different things. |
| Derived Attributes | An attribute whose value can be derived from other another attribute |  |
| Key Attribute | Any attribute for an entity whose values are unique for each instance of the entity. | It must be **unique** and used to pull someone from the database like an ID. |
| Domain | Set of values that can be assigned to an attribute, for each individual identity. | GPA has domains of 0 to 4. |

## Relationships

Relationships are placed in diamonds.

![](../../../.gitbook/assets/image%20%28584%29.png)

## Roles

![](../../../.gitbook/assets/image%20%28590%29.png)

* **Roles** tell you more about the relationship beyond what's in the diamond.
* Roles are straightforward/obvious, except in **recursive relationships**. 
  * Therefore, you need to put `father` and `son` to see what each is referring to.

## Structural Constraints

* **Cardinality Ratio Constraint**: specifies the number of relationship instances that an entity can participate in.
* **Participation Constraints**: 
  * **Total \(Existence Dependency\)**: Every entity in _the total set_ of employee entities must be related to a department entity via works-in.
  * **Partial:** Some or part of the set of employees are related to the department via a manager, but not necessarily all.

![For a department to exist, there has to be an employee managing it; not every employee is a manager.](../../../.gitbook/assets/image%20%28588%29.png)




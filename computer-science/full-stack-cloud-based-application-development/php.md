# PHP

## Resources

Help me.&#x20;

## Related Tools

### Content Management Systems (CMS)

PHP remains one of the widest used server-side technologies on the internet. It provides the underlying code for many popular content management systems (CMS) including [WordPress](https://wordpress.com), [Drupal](https://www.drupal.org), and [Joomla](https://www.joomla.org). A _CMS_ allows users to create and update their own websites without having to write a lot of complex code themselves.

### E-Commerce Sites

PHP also provides the underlying code for many e-commerce sites including [WooCommerce](https://woocommerce.com) and [Magento](https://magento.com). These e-commerce platforms offer a number of tools for selling products online. This way companies can focus on other aspects of their business without having to implement complex programming logic from scratch.

### PHP Frameworks

PHP contains built-in functionality for interacting with web data, _Vanilla PHP_, or PHP without any other tools, can be used on its own to create web application back-ends. But we don’t have to reinvent the wheel every time! Once we’re comfortable with the basics of the PHP language, we have our pick of powerful PHP frameworks to choose from! These frameworks provide scaffolding and solutions to common problems in back-end web development. Some popular PHP frameworks are [Laravel](https://laravel.com), [CakePHP](https://cakephp.org), and [Symfony](https://symfony.com).

## Getting Started

{% embed url="https://www.codecademy.com/learn/learn-php/modules/getting-started-with-php/cheatsheet" %}



### Terminal

When writing a PHP script file, we still need to denote that we are beginning our PHP code using `<?php`, but the closing tag is no longer required. It is typically left out by convention.

For example, if the following code were placed in **index.php**:

```php
<?
phpecho "Hello, World!";
```

When the code above is run, `"Hello, World!"` will be output to the terminal.

### Strings

Escape Sequences

{% embed url="https://www.php.net/manual/en/language.types.string.php#language.types.string.syntax.double" %}

### Concatenation

&#x20;Let’s see an example of string concatenation:

```
echo "one" . "two"; // Prints: onetwo
```

We can also combine, or chain, our operations to get a final result:

```
echo "one" . " " . "two" . " " . "three"; // Prints: one two three
```

#### Shorthand Concatenation

```php
$full_name = "Aisle";
$full_name .= " Nevertell";
echo $full_name; // Prints: Aisle Nevertell
```



## Variables

{% embed url="https://www.codecademy.com/learn/learn-php/modules/learn-php-variables/cheatsheet" %}



One common convention when naming PHP variables is to use an underscore between words on variable names with more than one word in their name. This is known as ** **_**snake case**_**:**

![](<../../.gitbook/assets/image (446).png>)

Call it with a dollar sign

```php
$favorite_food = "Red curry with eggplant, green beans, and peanuts";
echo $favorite_food; 

// Prints: Red curry with eggplant, green beans, and peanuts
```

Variables

PHP strings allow us to place variables directly into double quoted strings. These variables will be _parsed_ which means the computer will read the variables as the value they hold rather than see them as just a sequence of characters.

```php
$dog_name = "Tadpole";
$favorite_food = "treat";
$color = "brown";
 
echo "I have a ${color}ish dog named $dog_name and her favorite food is ${favorite_food}s.";
// Prints: I have a brownish dog named Tadpole and her favorite food is treats.
```

&#x20;PHP allows us to **specifically indicate the variable name by wrapping it in curly braces** to avoid any confusion. We’ll include the dollar sign followed by the variable name wrapped in curly braces:

```php
$dog_name = "Tadpole";
$favorite_food = "treat";
$color = "brown";
 
echo "I have a ${color}ish dog named $dog_name and her favorite food is ${favorite_food}s.";
// Prints: I have a brownish dog named Tadpole and her favorite food is treats.
```



## Misc

Escape Sequences:

{% embed url="https://www.php.net/manual/en/language.types.string.php#language.types.string.syntax.double" %}


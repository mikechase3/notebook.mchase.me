# Django Basics

## Quick Links

* Make sure you understand Python [basics](../../corepython/).
* Docs - [writing your first django app](https://docs.djangoproject.com/en/5.0/intro/tutorial01/)
* Also know bits of HTML/CSS/JS so you know how they work together.

## Refreshers

I'm doing a quiz type of approach. Skim over the answers.

### HTML

#### Including Headers in CSS

Here's a basic file. Answer:

1. How do you link a CSS file?
2. How do you change text within headers?

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <link rel="stylesheet" href="styles.css">
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HTML w/ CSS</title>

</head>
<body>
<section id="container">
    <h1 id="text">Django Time!</h1>
</section>
</body>
</html>

```

#### Using Forms

Here's questions to test understanding of the code below:

1. Which HTML tag is used to create the form for a hotdog?
2. What is the purpose of the `name` attribute in the `<input>` and `<select>` tags?
3. How can a user choose their preferred sausage type?
4. How are the checkboxes for toppings represented in this form?
5. How can a user select whether they want cheese or not?
6. How is the dropdown menu for bun selection created?
7. How is the list of available sauces presented in the form?
8. How can the user provide any additional comments or requests?
9. What is the purpose of the `id` attribute in the form elements?
10. How is the data from this form submitted?

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Hotdog Form Example</title>
</head>
<body>
  <form action="submission.html" method="POST">
    <h1>Create a hotdog!</h1>
    
    <label for="sausage">Sausage:</label>
    <input type="text" name="sausage" id="sausage">
    
    <label for="toppings">Toppings:</label>
    <input type="checkbox" name="topping" id="ketchup" value="ketchup">
    <label for="ketchup">Ketchup</label>
    <input type="checkbox" name="topping" id="mustard" value="mustard">
    <label for="mustard">Mustard</label>
    <input type="checkbox" name="topping" id="relish" value="relish">
    <label for="relish">Relish</label>
    
    <label for="cheese">Cheese:</label>
    <input type="radio" name="cheese" id="yes" value="yes">
    <label for="yes">Yes</label>
    <input type="radio" name="cheese" id="no" value="no">
    <label for="no">No</label>
    
    <label for="bun">Bun:</label>
    <select name="bun" id="bun">
      <option value="plain">Plain</option>
      <option value="sesame">Sesame</option>
      <option value="poppyseed">Poppy Seed</option>
    </select>
    
    <label for="sauce">Sauce:</label>
    <input list="sauces" id="sauce" name="sauce">
    <datalist id="sauces">
      <option value="ketchup"></option>
      <option value="mustard"></option>
      <option value="mayo"></option>
    </datalist>
    
    <label for="extra">Extra:</label>
    <textarea id="extra" name="extra" rows="3" cols="40"></textarea>
    
    <input type="submit" value="Submit">
  </form>
</body>
</html>

```

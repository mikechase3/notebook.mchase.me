# Flask

## Getting Started

### Creating a Flask Application Object
* You need to create an object for the Flask application.
* It's like creating the root of a tKinter app.

```python
from flask import Flask
...
app = Flask(__name__)  # Gets
```

### Routing
* Here's how you get started with something.
* Use `@app.route('/') to route a URL to a function displaying output.: 

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
  return "Hello, World!"
```


You can route multiple URL paths to a single view function: 
```python
@app.route('/')
@app.route('/home')
def home():
    return 'Hello, World!'


@app.route('/reporter')
def reporter():
    return 'Reporter Bio'
```

### Render HTML
You can render HTML like so:

```python
@app.route('/')
@app.route('/home')
def home():
    return '''
    <h1>Hello, Mike Chase!</h1>
    '''


@app.route('/reporter')  # Demonstrates linking to other pages.
def reporter():
    return '''
    <h2>Reporter Bio</h2>
    <a href="/"> Return to home page</a>  # Root is relative to the app?
    '''
```

### Variable Rules
* You can pass in variables within URLs.
* We can enforce the type of variable by using the syntax `<converter:variable_name>` within the `@app.route(...)` function.
* You can only enforce `string` (**not str**, which accepts any text without a `/`, `int`, `float`, `path` (like string but also accepts slashes), and `uuid` (which accepts UUID strings)
* These are called **converter types**.
* ~~converter types can be inferred.~~ not numeric inputs apparently. If it's a path, let it be inferred. Otherwise, specify the type. (I hope).

```python
@app.route('/reporter/<int:reporter_id>')  # Could just be `<reporter_id>` and converter type will infer it (somehow).
def reporter(reporter_id: int) -> str:
  return f'''  # MAKE SURE YOU PUT THIS F HERE MIKE CHASE. COME ON. YOUR IQ IS HIGHER THAN THAT.
    <h2>Reporter {reporter_id} Bio</h2>
    <a href="/">Return to home page</a>
    '''
```

You can test the above code by appending stuff to the end of the URL like `http://localhost:5000/reporter/35`
> "Reporter 34 Bio
> Return to home page



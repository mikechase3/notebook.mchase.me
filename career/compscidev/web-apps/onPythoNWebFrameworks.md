## Python Web Frameworks
There's a lot of python web frameworks:
* Appier: object oriented. Lightweight as possible. Not complex.
* Aspen: filesystem driven. Maps URLs to filesystem. No RegEx. 2.7
* BlueDream: medium/large projects split in componentys. 2.7
* Bobo: lightweight. Easy to use/remember. Uses WSSGI (python)
* Bottle: fast/simple WSGI for small web apps.
* CherryPy: likke other object oriented python programs. 
* Clastic: eliminates pitfalls/delays. Unpopular. 2.6/2.7
* Cyhclone: implements tornado api. Facebook.
* Django: What I'm learning; comprehensive. Extensible. Secure-ish.
* Falcon: performance focused. Web service oriented.
* Fantastico: dev-friendly publishingframework. Dynamic content gen. ORM.
* Flask: popular. Debugger. REST. Plugins.  Extensible. 
* Giotto: URL routing. RESTful. CURD patterns. Generic videws/models. 2.7
* Gork: old. Avoid
* Klein: micro framework. Web services.
* Morepath: WGSI micro framework. Routes to models. Model-Driven. Auto hyperlinks.
* Muffin: asynchronous stack & command line integ4ration. 
* Pylons: rapid/lightweight. Minimalist. Well-tested Py packages.
* Pyramid: powerful config, overridable asset specs, extensible templates.
* Tornado: asynchronous. Scales to many open connections. Long polling/websockets.
* Turbogears: old 2.7. calable. 
* Twisted: event-based networking. Allows multiple server/answer requests on same port.
* Uliweb: reusability, configurability, replacability. Old. Command line tools.
* Watson: unpopular. Event-based. Form library.
* Web.py: 2.7. Simple to use. Has a database/form library.
* web2py: one package, no dependencies. Old. Web based IDE. 
* webapp2: for python's google app engine. 2,7
* WebPages: user auth out of box, unpopular.
* wheezy.web: *fastest* web framework. High performance. Auth. Model update/validation.

## Django
* See also [django programming basics](compscidev/languages-and-architectures/python/misc-packages/django-basics.md)
* Good database support, well supported, python api, admin page, user stuff is cool.
* Maps URLs to "views".
* Deals with caching, authentication, cookies, etc.
* Supports **Jinja2** templating.
* Installs from `pip install Django`
  * Start a project: `django-admin startproject mikechasesite`
  * Define models w/ `from django.db import models`
    * Make classes inherit from models.Model
    * Assign variables to `models.CharField(max_length=50`
    * Call return statements with those variables.
    * Also CharField, TextField, DataField. 
    * Assign relationships with `name = models.ForeignKey(PrimaryKey)`
* Register models w/ the admin interface by inheriting from `django.contrib.admin.ModelAdmin`

### Useful Resources
I swear by [Bucky](https://www.youtube.com/playlist?list=PL6gx4Cwl9DGBlmzzFcLgDhKTTfNLfX1IK). Only
warning is this is for an older version you can't follow along exactly. For Python 2.7, made in 2018ish.
I can't wait to checkout his newer [pro django tutorials](https://www.youtube.com/playlist?list=PL6gx4Cwl9DGDYbs0jJdGefNN8eZRSwWqy)
from 2023, but I'm not a "pro" yet and the videos are much longer.
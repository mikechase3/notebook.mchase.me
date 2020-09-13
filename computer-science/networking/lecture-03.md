# Lecture 03: GET and HEAD

## AS 1 Problem Solving

1. Crawl one web page
2. Add a loop to crawl 100 web pages.

## URL Format

The general URL format is given by:

```text
scheme://[user:pass@]host[:port][/path][?query][#fragment]
```

* `user`: Username
* `pass`: Depreciated password.
* `:port`: The port number in the URL
* `/path`: Helps us find where the path is.
* `?query`: What information do we want to receive
* `#fragment`: Not sure

{% hint style="danger" %}
What is fragment and query for? What are examples?
{% endhint %}

## GET Request

* Use the `GET` request to get the entire HTML file.

```python
string request = "GET /" + path + query + " HTTP/1.0\n User-agent: UDCScrawler/1.0\n Host: " +...
```

1. The type of request.
2. Second, specify the path.
3. Specify the protocol
4. Specify the version number
5. Type in the `User-agent: udaytoncrawler/1.0` as whatever user agent you want.
6. End the line using an escape character.
7. Use the field name `Host:` for some reason. 
8. Type the actual host name.
9. Use a `\n` to start a new line.
10. Close the request by saying `Connection: close.`

## HEAD Request

* Use the `HEAD` request to only receive the header.
* Format it the same as the `GET` request

```python
string request = "GET /" + path + query + " HTTP/1.0\nUser-agent: UDCScrawler/1.0\nHost: " +...
```

## URL Parser

```python
def parse(self, string):  # String is a URL
    self.query = ''  # Default query is an empty string
    self.path = '/'  # The default path.
    self.port = '80'  $ default port.
    self.host = ''  # The host is always defined for valid URLs.
    
    index = string.find('\n')
    if index != -1:
    string = string[0:index]  # remove the line break that is in the end.
    
    # remove 'http://' or 'https://' if it is present in the given URL.
    index = string.find '://')
    if index != 1:
        string = string[index + 3:]
        
    # Remove fragment from url
    index = string.find('#')
    if index != -1:  # if it found a fragment
        string = string[:index]  # Strip fragment
        
    # Remove user:pass@ if it exists.
    
    
```




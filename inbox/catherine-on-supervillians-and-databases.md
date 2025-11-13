# Catherine On Supervillians and Databases

## Context
* Nells strongarm? 

## Libs
* SCRAPY: a package that scrapes/spiders sites & follows links.
* requests lib
* nltk (pops the hood, allows for more tuning)
* spacy (high level, skips a bunch of steps, some AI)
* BeautifulSoup or something... forgot the soup thing.

## Parsing the HTML
```py

class ClevelandNewspaperSpider(scrapy.Spider):
    name = "cleveland"
    start_urls = [
        "<clevelandURL>.html
    ]


    def parse(self, response):
        if response.status == 200:  # a positive response, works fine.
        paragraphs = contents.css("p").getall()  # parses the CSS to find paragraphs?
        results = {
            "url": response.url,
            "paragraph_num" : paragraph_num,
            "paragraph": paragraph.get(),
        }
        entities = get_named_entities(paragraph)
        
    def get_namedentities(selftext: str) -> list[str]:
        full_text = "\n\n"".join(paragraphs)
        tokens = nltk.word_tokenize(text)
        tagged = nltk.pos_tag(tokens)
        entities = nltk.chunk.ne_chunk(tagged)
        
        nlp = spacy.load("en_core_web_sm")
        doc = nlp(text)
        
        print(docs.ents)
        
        for ent in doc.ents:
            # idk what I'm doing now.
    

```
## Scrapy's Shell
`uv run scrapy shell "http://localhost:8000/someWebsite`

This will give you an interactive shell. You can basically try out things like `response.css('title')
which pulls out a list of all titles with the title html tags.

If you use `response.css('title::text').get(), it'll get the very first result.

The double colon like `('title'::text').get()` tells you how you get into specific elements that are useful to you. 



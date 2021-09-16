import scrapy

# open search_fr.txt
with open('search_fr.txt','r') as firstfile:
      
    # read content from first file
    for line in firstfile:
        #line = {"name":"Abelia biflora", "anchor":"Abelia_biflora"},

class BlogSpider(scrapy.Spider):
    name = 'hortispider'
    start_urls = ['https://fr.hortipedia.com/Hortibox/$1/resources/imgs/icons/*']

    def parse(self, response):
        for title in response.css('body-grey md-dialog-is-showing'):
            yield {'title': title.css('').get()}

        for next_page in response.css(''):
            yield response.follow(next_page, self.parse)

"""
TARGET URL = https://fr.hortipedia.com/ + "anchor" du fichier search_fr.js

--> Get the name of the fourteen files inside ./resources/imgs/icons :)

<!-- growth -->
<div aria-label=""><img src="../resources/imgs/icons/lifeform1.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/habitus_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/plant_use_NA.png"></div>

<!-- growing conditions -->
<div aria-label=""><img src="../resources/imgs/icons/exposure_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/moisture_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/soil_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/hardiness2.png"></div>

<!-- leaf -->
<div aria-label=""><img src="../resources/imgs/icons/leaf_shape_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/leaf_division_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/leaf_arrangement2.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/leaf_retention3.png"></div>

<!-- flower -->
<div aria-label=""><img src="../resources/imgs/icons/flower_shape_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/inflorescence_NA.png"></div>
<div aria-label=""><img src="../resources/imgs/icons/fruit24.png"></div>
"""
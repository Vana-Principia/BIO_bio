import os
import urllib.request

from bs4 import BeautifulSoup
import requests
import re

import csv  

def getPlantsInformation(url):
    page = requests.get(url).text
    soup = BeautifulSoup(page, "html.parser")
    script = soup.find(string=re.compile("scope.content"))
    if isinstance(script, str):
        m = re.search('{"hortibox":{"(.+?)}};', script)
        if m:
            return m.group(1)
        else:
            return ''
    else:
        return ''
    
def testToString(toTest):
    if toTest:
        return toTest.group(1)
    else:
        return ''
    
def separateInformation(name, content):
    author = testToString(re.search('author":"(.+?)",', content))    
    familia = testToString(re.search('"familia":"(.+?)",', content))
    lifeform = testToString(re.search('"lifeform":"(.+?)",', content))
    habitus = testToString(re.search('"habitus":"(.+?)",', content))
    plantUse = testToString(re.search('"plantUse":"(.+?)",', content))
    height = testToString(re.search('"height":"(.+?)",', content))
    exposure = testToString(re.search('"exposure":"(.+?)",', content))
    moisture = testToString(re.search('"moisture":"(.+?)",', content))
    soil = testToString(re.search('"soil":"(.+?)",', content))
    hardiness = testToString(re.search('"hardiness":"(.+?)",', content))
    leafShape = testToString(re.search('"leafShape":"(.+?)",', content))
    leafDivision = testToString(re.search('"leafDivision":"(.+?)",', content))
    leafArrangement = testToString(re.search('"leafArrangement":"(.+?)",', content))
    leafRetention = testToString(re.search('"leafRetention":"(.+?)",', content))
    autumnColour = testToString(re.search('"autumnColour":"(.+?)",', content))
    floweringPeriod = testToString(re.search('"floweringPeriod":"(.+?)",', content))
    flowerColour = testToString(re.search('"flowerColour":"(.+?)",', content))
    flowerShape = testToString(re.search('"flowerShape":"(.+?)",', content))
    inflorescence = testToString(re.search('"inflorescence":"(.+?)",', content))
    fruit = testToString(re.search('"fruit":"(.+?)",', content))
    ordo = testToString(re.search('"tax":{"ordo":"(.+?)",', content))
    superordo = testToString(re.search('"superordo":"(.+?)",', content))
    subclassis = testToString(re.search('"subclassis":"(.+?)",', content))
    classis = testToString(re.search('"classis":"(.+?)",', content))
    subdivisio = testToString(re.search('"subdivisio":"(.+?)",', content))
    divisio = testToString(re.search('"divisio":"(.+?)",', content))
    familia = testToString(re.search('"familia":"(.+?)",', content))

    
    """print("author = " + author
          + ", familia = " + familia
          + ", lifeform = " + lifeform
          + ", habitus = " + habitus
          + ", plantUse = " + plantUse
          + ", height = " + height
          + ", exposure = " + exposure
          + ", moisture = " + moisture
          + ", soil = " + soil
          + ", hardiness = " + hardiness
          + ", leafShape = " + leafShape
          + ", leafDivision = " + leafDivision
          + ", leafArrangement = " + leafArrangement
          + ", leafRetention = " + leafRetention
          + ", autumnColour = " + autumnColour
          + ", floweringPeriod = " + floweringPeriod
          + ", flowerColour = " + flowerColour
          + ", flowerShape = " + flowerShape
          + ", inflorescence = " + inflorescence
          + ", fruit = " + fruit
          + ", ordo = " + ordo
          + ", superordo = " + superordo
          + ", subclassis = " + subclassis
          + ", classis = " + classis
          + ", subdivisio = " + subdivisio
          + ", divisio = " + divisio
          + ", familia = " + familia)"""
          
    return [name, author, familia, lifeform, habitus, plantUse, height, exposure, moisture, soil,
          hardiness, leafShape, leafDivision, leafArrangement, leafRetention, autumnColour,
          floweringPeriod, flowerColour, flowerShape, inflorescence, fruit, ordo,
          superordo, subclassis, classis, subdivisio, divisio, familia]

# open search_fr.txt
with open('search_fr2.txt','r') as firstfile:
    
    header = ['name', 'author', 'familia', 'lifeform', 'habitus', 'plantUse', 'height', 'exposure', 'moisture', 'soil',
              'hardiness', 'leafShape', 'leafDivision', 'leafArrangement', 'leafRetention', 'autumnColour',
              'floweringPeriod', 'flowerColour', 'flowerShape', 'inflorescence', 'fruit', 'ordo',
              'superordo', 'subclassis', 'classis', 'subdivisio', 'divisio', 'familia']
    
    with open('plantsDatabase.csv', 'w', encoding='UTF8') as f:
        writer = csv.writer(f)
        writer.writerow(header)
          
        # read content from first file
        for line in firstfile:
            #line = {"name":"Abelia biflora", "anchor":"Abelia_biflora"},
            parsedLine = line.rsplit('"')
            anchor = parsedLine[7]
            url = "https://fr.hortipedia.com/" + anchor
            #print(url)
            
            content = getPlantsInformation(url)
            if content != '':
                data = separateInformation(anchor, content)
                writer.writerow(data)
            
        f.close()
        
"""
TARGET URL = https://fr.hortipedia.com/ + "anchor" du fichier search_fr.js

--> Get the name of the fourteen files inside ./resources/imgs/icons :)

<!-- growth -->
{{hortibox.lifeform}}
{{hortibox.habitus}}
{{hortibox.plantUse}}

{{hortibox.height}}

<!-- growing conditions -->
{{hortibox.exposure}}
{{hortibox.moisture}}
{{hortibox.soil}}
{{hortibox.hardiness}}

<!-- leaf -->
{{hortibox.leafShape}}
{{hortibox.leafDivision}}
{{hortibox.leafArrangement}}
{{hortibox.leafRetention}}

<!-- flower -->
{{hortibox.flowerShape}}
{{hortibox.inflorescence}}
{{hortibox.fruit}}
"""
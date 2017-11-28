import urllib.request as urllib2




respone = urllib2.urlopen('http://www.baidu.com')
print(respone.read())

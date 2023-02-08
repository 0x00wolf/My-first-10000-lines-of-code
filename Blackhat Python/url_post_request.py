import urllib.parse
import urllib.request

url = 'http://boodelyboo.com'
info = {'user': 'tim', 'passwd': '31337'}
data = urllib.parse.urlencode(info).encode() # data is now of type bytes

req = urllib.request.Request(url, data)
with urllib.request.urlopen(req) as response: # POST
    content = resonse.read()

print(content)

import requests
resp = requests.post('https://textbelt.com/text', {
    'phone': '+09023291275',
    'message': 'Hello, I am a phishing text. Does this feel a little Phishy to you? Har har har',
    'key': 'textbelt',
    })
print(resp.json())

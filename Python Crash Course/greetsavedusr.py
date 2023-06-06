import json

filename = 'users.json'
with open(filename, 'r') as f:
    username = json.load(f)
    print(f"Welcome back: {username}")
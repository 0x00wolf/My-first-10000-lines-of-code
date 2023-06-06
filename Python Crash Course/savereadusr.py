import json

username = input("Enter your username: ")
filename = 'users.json'
with open(filename, 'w') as f:
    json.dump(username, f)
    print(f"We remember, {username}.")
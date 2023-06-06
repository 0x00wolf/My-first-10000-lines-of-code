import json

def get_stored_username():
    """ Get a stored username if available"""
    filename = 'users.json'
    try:
        with open(filename) as f:
            username = json.load(f)
    except FileNotFoundError:
        return None
    else:
        return username

def greet_user():
    """Greet user, or get user info"""
    username = get_stored_username()
    if username: 
        print(f"Welcome back, {username.title()}")
    else:
        usename = input("What is your name?")
        filename = 'users.json'
        with open(filename, 'w') as f:
            json.dump(username, f)
            print(f"We'll remember you when you come back, {username}!")

greet_user()

    

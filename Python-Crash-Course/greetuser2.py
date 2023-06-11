import json

def get_stored_username():
    """Get stored username"""
    filename = 'username.json'
    try:
        with open(filename, 'r') as f:
            username = json.load(f)
    except FileNotFoundError:
        return None
    else:
        return username

def get_new_user():
    """Add the user to user.json"""
    username = input("User, enter your username: ")
    filename = 'username.json'
    with open(filename, 'w') as f:
        json.dump(username, f)
    return username

def greet_user():
    """Do the thing"""
    username = get_stored_username()
    if username:
        print(f"Hello {username.title()}, welcome to the jungle.")
    else:
        username = get_new_user()
        print(f"{username} you will not be forgotten.")

greet_user()


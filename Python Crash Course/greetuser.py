import json

#   Load the username if stored previously
#   Else, add new user.abs


def greet_user():
    """ Greet the user, if no user, get username """
    filename = 'users.json'
    try:
        with open(filename) as f:
            username = json.load(f)
    except FileExistsError:
        username = input("What's your username: ")
        with open(filename, 'w') as f:
            json.dump(username, f)
            print(f"{username.title()} you are now in control.")
    else:
        print(f"Welcome back {username.title()}.")
    
greet_user()
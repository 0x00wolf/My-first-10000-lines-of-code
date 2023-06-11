import json

def get_stored_user():
    filename = 'dauser.json'
    try:
        with open(filename, 'r') as f:
            username = json.load(f)
            return username
    except FileNotFoundError:
        return None

def add_new_user():
    filename = 'dauser.json'
    username = input("Enter your username: ")
    with open(filename, 'w') as f:
        json.dump(username, f)
    return username

def greet_user():
    iscorrect = get_stored_user()
    if iscorrect == None:
        add_new_user()
        print(f"Hello {username}, how goes it bud.")
    else:
        print(f"Hello {username}, how goes it bud.")

greet_user()




    
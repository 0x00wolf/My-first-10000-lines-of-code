import json

def get_fav_number():
    """recall fav number, or get if not already stored"""
    filename = 'favoritenumber.json'
    try:
        with open(filename, 'r') as f:
            favorite_number = json.load(f)
            print(f"Your favorite number is : {str(favorite_number)}")
    except FileNotFoundError:
        favorite_number = input("What is your favorite number: ")
        with open(filename, 'w') as f:
            favorite_number = json.dump(favorite_number, f)
            print(f"Let me guess... Your favorite number is {str(favorite_number)}")

get_fav_number()
from name_function import get_formatted_name

print("Enter 'q' at any time to quit.")
while True:
    first = input("\nPlease give me your first name: ")
    if first == 'q':
        break
    middle = input("\nInput if you have a middle name, else hit enter: ")
    if middle == 'q':
        break
    last = input("Please give me your last name: ")
    if last == 'q':
        break
        
    formatted_name = get_formatted_name(first, last)
    print(f"\tNeatly formatted name: {formatted_name}.")
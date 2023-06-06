# working with files in python
filename = 'txt_files/pi_digits.txt'

with open(filename) as file_object:
    contents = file_object.read()

print(contents.rstrip())

#using an absolute path
with open('/home/oldog/dev-env/python/crash_course/txt_files/pi_digits.txt') as file_object:
    contents = file_object.read()

print(contents.strip())

# Reading line by line
filename = '/home/oldog/dev-env/python/crash_course/txt_files/pi_digits.txt'

with open(filename) as file_object:
    for line in file_object:
        print(line.rstrip())

# making a list of lines from a file
filename = 'txt_files/pi_digits.txt'
with open(filename) as file_object:
    lines = file_object.readlines()

for line in lines:
    print(line.rstrip())

#working with a files contents
pi_string = ''
for line in lines:
    pi_string += line.strip()

print(pi_string)
print("Length is: " + str(len(pi_string)))
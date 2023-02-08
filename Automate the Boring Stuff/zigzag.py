import time, sys
indent = 0 # How many spaces to indent
indent_increasing = True # Whether the indentation is increasing or not

try:
    while True: # The main program
        print(' '*indent, end='')
        print('********')
        time.sleep(0.1) # pause for 1/10 of a second.

        if indent_increasing:
            # Increase the number of spaces.
            indent = indent + 1
            if indent == 10:
                # Change direction
                indent_increasing = False
        
        else:
            # Decreases the number of spaces.
            indent = indent - 1
            if indent == 0:
                # And then
                indent_increasing = True
except KeyboardInterrupt:
    sys.exit()
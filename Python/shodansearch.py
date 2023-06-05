#!/usr/bin/env python

# shodan_ips.py
# search SHODAN and print a list of IPs matching the query

import shodan
import sys

# Configuration
API_KEY = "YOUR_API_KEY"

# Input validation
if len(sys.argv) == 1:
    print('Usage: %s <search query>' % sys.argv[0])
    sys.exit(1)

try:
    # setup the api
    api = shodan.Shodan(API_KEY)

    # perform the search
    query = ' '.join(sys.argv[1:])
    result = api.search(query)

    # loop through the matches and print each ip
    for service in result['matches']:
        print(service['ip_str'])
except Exception as e:
    print('Error: %s' % e)
    sys.exit(1)

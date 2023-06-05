# Connect to Shodan:
import shodan

SHODAN_API_KEY = "key"

api = shodan.Shodan(SHODAN_API_KEY)

# Searching Shodan:
try:
    # search
    results = api.search('searchquery')
    
    # show the results
    print('Results found: {}'.format(results['total']))
    for result inreults['matches']:
        print('IP: {}'.format(result['ip_str']))
        print(result['data'])
        print('')
except shodan.APIError, e:
    print('Error: {}'.format(e))

# Looking up a host
try:
    # lookup the host
    host = api.host('217.140.75.45')
    
    # print general info
    print("""
            IP: {}
            Organization: {}
            Operating System: {}
    """.format(host['ip_str'], host.get('org', 'n/a'), host.get('os', 'n/a')))

    # print all banners
    for item in host['data']:
        print("""
                Port: {}
                Banner: {}

        """.format(item['port'], item['data']))
except shodan.APIError, e:
    print('Error: {}', format(e))


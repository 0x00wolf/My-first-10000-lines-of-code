import shodan

SHODAN_API_KEY = "insert key"

api = shoda.Shodan(SHODAN_API_KEY)

# Looking up a host
host = api.host('217.140.75.45')

# print general info
print("""
        IP: {}
        Organization: {}
        Operating System: {}
""".format(host['ip_str'], host.get('org', 'n/a'),

# print all banners
for item in host['data']:
    print("""
              Port: {}
              Banner: {}
    """.format(item['port'], item['data']))

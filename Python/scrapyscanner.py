# Code courtesy of Hackers Arise
import scapy
import sys
import signal
import os

# function to handle when user enters ctrl+c
def signal_handler(signal, frame):
    print('\n===================')
    print('Execution aborted by User')
    print('=================')
    os.system("kill -9 " +  str(os.getpid()))
    sys.exit(1)

# function to exit
def signal_exit(signal, frame):
    print('Signal exit')
    sys.exit(1)

# function to remind user of proper usage
def usage():
    if len(sys.argv) < 3:
        print("\nUsage:")
        print("\tpython scapyscanner.py -i <interface>\n")
        sys.exit(1)

# function to sniff packets
def sniffpackets(packet):
    try:
        SRCMAC = packet[0].addr2
        DSTMAC = packet[0].addr1
        BSSID = packet[0].addr3
    except:
        print("Cannot read MAC address.")
        print(str(packet).encode("hex"))
        sys.exc_clear()

    try:
        SSIDSize = packet[0][Dot11Elt].len
        SSID = packet[0][Dot11Elt].info
    except:
        SSID = ""
        SSIDSize = 0

# check if packet type =0 and subtype 8 (Beacon frames)
    if packet[0].type == 0:
        ST = packet[0][Dot11].subtype
        if str(ST) == '8' and SSID != "" and DSTMAC.lower() == "ff:ff:ff:ff:ff:ff":
            p = packet[Dot11Elt]
            cap = packet.sprintf("{Dot11Beacon:%Dot11Beacon.cap%}"
                                 "{Dot11ProbeResp:%Dot11ProbeResp.cap%}").split('+')
            channel = None
            crypto = set()

# create a function to make sure that SSID's are not duplicated in our display
def init_process():
    global ssid_list
    ssid_list = {}
    global s
    s = conf.L2socket(iface=newiface)

# function to place wireless into monitor mode
def setup_monitor(iface):
    print("Setting up sniffing options...")
    os.system('ifconfig ' + iface + ' down')
    try:
        os.system('iwconfig ' + iface + ' mode monitor')
    except:
        print('Failed to setup your interface in monitor mode.')
        sys.exit(1)
    os.system('ifconfig ' + iface + ' up')
    return iface

# check if user == root and if not print message
def check_root():
    if not os.geteuid() == 0:
        print('You must run this script with root privileges')
        exit(1)

# Main code body
if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal_handler)
    usage()
    check_root()
    parameters = {sys.argv[1]:sys.argv[2]}
    if "mon" not in str(parameters["-i"]):
        newiface = setup_monitor(parameters["-i"])
    else:
        newiface = str(parameters["-i"])
    init_process()
    print("Starting wifi Sniffer")
    print("Sniffing on interface " + str(newiface) + "...\n")
    sniff(iface=newiface, prn=sniffpackets, store=0)
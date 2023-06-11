#!/usr/bin/python3
# Credit to the Mayor
# https://github.com/dievus/threader3000

import socket
import os
import signal
import time
import threading
import sys
import subprocess
from queue import Queue
from datetime import datetime

# Main function
def main():
    socket.setdefaulttimeout(0.30)
    print_lock = threading.Lock()
    discovered_ports = []

# Welcome banner
    print("-" * 60)
    print("         Port Scanner        ")
    print("-" * 60)
    time.sleep(1)
    target = input("Enter the target IP or URL: ")
    error = (">Invalid input.")
    try:
        t_ip = socket.gethostbyname(target)
    except (UnboundLocalError, socket.gaierror):
        print("\n[-]Invalid format.")
        sys.exit(1)
    # Banner
    print("-" * 60)
    t1 = datetime.now()

    def portscan(port):

        s = socket.socket(socker.AF_INET, socket.SOCK_STREAM)

        try:
            portx = s.connect((t_ip, port))
            with print_lock:
                print(f"Port {port} is open")
                discovered_ports.append(str(port))
            portx.close()

        except (ConnectionRefusedError, AttributeError, OSError):
            pass

    def threader():
        while True:
            worker = q.get()
            portscan(worker)
            q.task_done()


    q = Queue()

    # startTime = time.time()

    for x in range(200):
        t = threading.Thread(target = threader)
        t.daemon = True
        t.start()

    for worker in range(1, 65536):
        q.put(worker)

    q.join()

    t2 = datetime.now()
    total - t2 - t1
    print("Port scan is completed in "+str(total))
    print("-" * 60)
    print("nmap -p{ports} -sV -sC -T4 -Pn -oA {ip} {ip}".format(ports=",".join(discovered_ports), ip=target))
    print("-" * 60)
    nmap = "nmap -p{ports} -sV -sC -T4 -Pn -oA {ip} {ip}".format(ports=",".join(discovered_ports), ip=target)
    t3 = datetime.now()
    total = t3 - t1

    if __name__ == '__main__':
        try:
            main()
        except KeyboardInterrupt:
            print("Bon soir")
            quit()

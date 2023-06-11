from platform import system

def get_platform():
    platform_is = system()
    if platform_is == 'Windows':
        print('Windows')
    elif platform_is == 'Darwin':
        print('Mac')
    elif platform_is == 'Linux':
        print('Linux')
    elif platform_is == 'Java':
        print('Java')
    return platform_is
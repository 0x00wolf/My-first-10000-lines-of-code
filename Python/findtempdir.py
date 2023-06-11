import tempfile

def getTempDir():
    temporary_dir = tempfile.gettempdir()
    return temporary_dir